#pragma once

#include <memory>
#include <string>

class SubDevice{
public:
  SubDevice(std::uint64_t id, int age,std::string name, std::uint64_t superSecretNumber);
  SubDevice(const SubDevice&) = delete; // no copy ctor
  SubDevice(SubDevice&&) noexcept = default; // "If T's move constructor is not noexcept and is not CopyInsertable into *this, vector will use the throwing move constructor." https://en.cppreference.com/w/cpp/container/vector/emplace_back
  ~SubDevice(); // cannot be default

  // overrides
  std::uint64_t id() const noexcept;
  int age() const noexcept;
  const std::string& name() const noexcept;

  // subclass functions
  std::uint64_t superSecretNumber() const noexcept;

private:
  int _id;
  int _age;
  std::string _name;
  std::uint64_t _superSecretNumber;
};
