#include "manager.h"
#include "subdevice.h"


struct DeviceManager::Impl {
  Impl();
  ~Impl();

  std::vector<std::shared_ptr<SubDevice>> devices; // has to be SubDevice exactly in order to allow emplace_back construction
};

DeviceManager::Impl::Impl()
  : devices()
{
  ;
}

DeviceManager::Impl::~Impl() = default;






DeviceManager::DeviceManager()
  : mImpl(std::make_unique<Impl>())
{
  ;
}

DeviceManager::~DeviceManager() = default;

std::shared_ptr<SubDevice>&
DeviceManager::createSubDevice(std::uint64_t id,int age,const std::string& name)
{
  auto& newDevice = mImpl->devices.emplace_back(std::make_shared<SubDevice>(id,age,name,42));
  // Could do other stuff here to initialise state
  return newDevice;
  //return static_cast<std::shared_ptr<Device>>(newDevice); //  error: non-const lvalue reference to type 'shared_ptr<...>' cannot bind to a temporary of type 'shared_ptr<...>'
}

const std::shared_ptr<SubDevice> // cannot be reference to std::shared_ptr, as may have to return a nullptr
DeviceManager::matches(
  const std::function<bool(const std::shared_ptr<SubDevice>&)>& matcher) const // cannot be device due to no known cast. Not const as you may want to alter the returned item.
{
  for (auto& d : mImpl->devices) {
    if (matcher(d)) {
      return d;
    }
  }
  return nullptr;
}

void
DeviceManager::reserve(std::size_t capacity)
{
  mImpl->devices.reserve(capacity);
}

std::size_t
DeviceManager::size() const noexcept
{
  return mImpl->devices.size();
}

void
DeviceManager::clear()
{
  mImpl->devices.clear();
}