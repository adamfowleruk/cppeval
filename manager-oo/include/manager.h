#pragma once

#include "device.h"
#include "subdevice.h"

#include <memory>
#include <functional>

class DeviceManager {
public:
  DeviceManager();
  ~DeviceManager(); // PIMPL - cannot default

  std::shared_ptr<SubDevice>& createSubDevice(std::uint64_t id,int age,const std::string& name);

  const std::shared_ptr<SubDevice> matches(
    const std::function<bool(const std::shared_ptr<SubDevice>&)>& matcher) const;

  void reserve(std::size_t capacity);
  std::size_t size() const noexcept;
  void clear();

private:
  struct Impl; // fwd decl
  std::unique_ptr<Impl> mImpl; // PIMPL idiom
};
