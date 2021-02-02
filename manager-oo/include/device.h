#pragma once

#include <string>

/**
 * Basic Device 'interface' class. A typical pattern.
 */
class Device {
public:
  Device() = default;
  virtual ~Device() = default;

  virtual std::uint64_t id() const noexcept = 0;
  virtual int age() const noexcept = 0;
  virtual const std::string& name() const noexcept = 0;
};