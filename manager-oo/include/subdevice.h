#pragma once

#include "device.h"

#include <memory>

class SubDevice : public Device {
public:
  SubDevice(std::uint64_t id, int age,std::string name, std::uint64_t superSecretNumber);
  SubDevice(const SubDevice&) = delete; // no copy ctor
  SubDevice(SubDevice&&) = delete; // no move ctor
  ~SubDevice(); // cannot be default

  // overrides
  std::uint64_t id() const noexcept override;
  int age() const noexcept override;
  const std::string& name() const noexcept override;

  // subclass functions
  std::uint64_t superSecretNumber() const noexcept;

private:
  struct Impl; // fwd decl
  std::unique_ptr<Impl> mImpl; // PIMPL idiom
};
