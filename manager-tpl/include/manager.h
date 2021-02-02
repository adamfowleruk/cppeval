#pragma once

#include <memory>
#include <functional>
#include <vector>
#include <variant>

/**
 * Note: We want to have a single device manager for many types of devices,
 * but to specify the type of each one on creation. We want to retrieve devices
 * with a particular type and ID. We only want to incur the maximum memory cost
 * for the devices in use in the application, and not all potential Device types.
 * 
 * Ideally we want to avoid heap allocation completely, but not suffer performance
 * degradation.
 */

template <typename... Ts>
class DeviceManager {
public:
  DeviceManager() = default;
  ~DeviceManager() = default;

  // Now called createDevice as we pass the specific type in as a template parameter
  template <typename T, typename... Args>
  T& createDevice(Args... args)
  {
    return std::get<T>(
      devices.emplace_back( std::in_place_type<T>, args..., 42 )
    );
  }

  // TODO replace std::function in the below with a generic Callable template parameter
  template <typename T>
  void processMatches(
    const std::function<bool(const T&)>& matcher, 
    const std::function<void(T&)>& processor)
  {
    // The type is stated explicitly to avoid const reference
    // for (auto d = devices.begin(); d != devices.end(); ++d) {
    //   if (matcher(std::get<T>(*d))) {
    //     processor(std::get<T>(*d));
    //   }
    // }
    for (auto& d : devices) {
      if (matcher(std::get<T>(d))) {
        processor(std::get<T>(d));
      }
    }
  }

  void reserve(std::size_t capacity)
  {
    devices.reserve(capacity);
  }

  std::size_t size() const noexcept
  {
    return devices.size();
  }

  void clear()
  {
    devices.clear();
  }

private:
  std::vector<std::variant<Ts...>> devices;
};
