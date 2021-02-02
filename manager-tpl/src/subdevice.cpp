#include "subdevice.h"

SubDevice::SubDevice(std::uint64_t id, int age,std::string name, std::uint64_t superSecretNumber)
  : _id(id),_age(age),_name(name),_superSecretNumber(superSecretNumber)
{
  ;
}

SubDevice::~SubDevice() = default;

// overrides
std::uint64_t
SubDevice::id() const noexcept
{
  return _id;
}

int
SubDevice::age() const noexcept
{
  return _age;
}

const std::string&
SubDevice::name() const noexcept
{
  return _name;
}

// subclass functions
std::uint64_t
SubDevice::superSecretNumber() const noexcept
{
  return _superSecretNumber;
}