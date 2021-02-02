#include "subdevice.h"
#include "manager.h"

#include <iostream>
#include <chrono>

/**
 * C++ example showing a 'modern' way to wrap a container and manage the
 * lifecycle of objects within it. Those objects use variadic templates, and
 * avoid use of pointers entirely, allowing full stack allocation and no
 * heap usage
 * 
 * Compare and contrast this memory use and CPU use in Valgrind with the
 * manager-oo version which uses Object Orientation and inheritance and heap
 * allocation.
 */

int main() {
  // create manager
  DeviceManager<SubDevice> mgr;
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
    auto& person = mgr.createDevice<SubDevice>(i,11 + ((i % 5)* 10),names[i % 5]);
    // CHANGE: Note in the above it's now createDevice and I pass in SubDevice as a type template parameter

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
    // Only major change - processMatches function so I don't have to handle 'no matches' return value
    // Note: Could also have a processFirstMatch function to reproduce the OO example's functionality exactly
    mgr.processMatches<SubDevice>(
      [i] (const SubDevice& d) -> bool {
        return d.id() == i;
      }
      ,
      [&found] (SubDevice& d) -> void {
        ++found;
      }
    );
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