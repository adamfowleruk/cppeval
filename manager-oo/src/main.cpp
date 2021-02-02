#include "subdevice.h"
#include "manager.h"

#include <iostream>
#include <chrono>

/**
 * C++ example showing a 'classical' way to wrap a container and manage the
 * lifecycle of objects within it. Those objects use OO inheritance, and
 * apply the PIMPL idiom for their implementation. This uses heap allocation
 * for all of the pointers.
 * 
 * Compare and contrast this memory use and CPU use in Valgrind with the
 * manager-tpl version which uses templates and no inheritance and stack
 * allocation only.
 */

int main() {
  // create manager
  DeviceManager mgr;
  std::vector<std::string> names = {
    "Adam Fowler","Leo Fowler","Zack Fowler","Judas Fowler","Horatio Fowler"
  };

  // populate
  std::cout << "Creation progress:   " << std::flush;
  std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
  mgr.reserve(1'000'000);
  for (auto i = 0;i < 1'000'000;++i) {
    // suppress compiler warning about person being unused
    [[maybe_unused]]
    auto& person = mgr.createSubDevice(i,11 + ((i % 5)* 10),names[i % 5]);
    // In real life, I may populate/modify my new person object here

    if (0 == i%1000) {
      std::cout << "." << std::flush;
    }
  }
  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
  std::cout << std::endl;
  std::cout << "Insert completed in "
            << (std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000000.0)
            << " seconds" << std::endl;

  // find
  int found = 0;
  std::cout << "Find by ID progress: " << std::flush;
  begin = std::chrono::steady_clock::now();
  for (auto i = 0;i < 1'000'000;i += 10'000) {
    // error: non-const lvalue reference to type 'shared_ptr<...>' cannot bind to a temporary of type 'shared_ptr<...>'
    // So has to be const... but pointed-to object CAN be modified 
    const auto& second = mgr.matches([i] (const std::shared_ptr<SubDevice>& d) -> bool {
      return d->id() == i;
    });
    if (nullptr != second) {
      ++found;
    }
    if (0 == i%1000) {
      std::cout << "." << std::flush;
    }
  }
  end = std::chrono::steady_clock::now();
  std::cout << std::endl;
  std::cout << "Found " << found << " people by ID" << std::endl;
  std::cout << "Find completed in "
            << (std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000000.0)
            << " seconds" << std::endl;

  return 0;
}