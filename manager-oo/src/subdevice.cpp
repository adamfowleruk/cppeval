
#include "subdevice.h"

struct SubDevice::Impl {
  Impl(std::uint64_t id, int age,std::string name, std::uint64_t superSecretNumber);
  ~Impl();

  std::uint64_t id;
  int age;
  std::string name;
  std::uint64_t superSecretNumber;
};

SubDevice::Impl::Impl(std::uint64_t id, int age,std::string name, std::uint64_t superSecretNumber)
  : id(id),age(age),name(name),superSecretNumber(superSecretNumber)
{
  ;
}

SubDevice::Impl::~Impl()
{
  ;
}






SubDevice::SubDevice(std::uint64_t id, int age,std::string name, std::uint64_t superSecretNumber)
  : mImpl(std::make_unique<Impl>(id,age,name,superSecretNumber))
{
  ;
}

SubDevice::~SubDevice()
{
  ;
}

// overrides
std::uint64_t
SubDevice::id() const noexcept
{
  return mImpl->id;
}

int
SubDevice::age() const noexcept
{
  return mImpl->age;
}

const std::string&
SubDevice::name() const noexcept
{
  return mImpl->name;
}

// subclass functions
std::uint64_t
SubDevice::superSecretNumber() const noexcept
{
  return mImpl->superSecretNumber;
}