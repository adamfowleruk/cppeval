#include "oo.h"
#include "tpl.h"

#include <iostream>
#include <chrono>

/**
 * C++ example comparing a classic object orientated (dynamic polymorphism) use case
 * with a modern C++17 templated (static polymorphism) equivalent.
 * 
 * Memory use for each object instance is shown.
 * 
 * Note we are using shared_ptr for the comparison as this is typical when passing 
 * dervied class instances around within managed C++ code.
 * 
 * In particular note the overhead of the vtable and shared_ptr for referencing
 * the instances using dynamic polymorphism. The calls are also extra CPU
 * overhead as there are multiple following of pointers (one for the shared ptr
 * and one for the vtable to function ptr).
 * 
 * Also worthy of note is that the rect, circ, and sqr classes will be
 * constructed on the heap, not the stack, for the dynamic polymorphism
 * variant. For iterating over thousands of objects (like you would do when
 * performing regular 'dirty' screen region rendering), the performance
 * cost of not having CPU cache locality will also slow down complex
 * algorithms executed in tight loops.
 * 
 * Note: On Win10 with CLang the OO version uses 136 bytes of RAM (stack + heap)
 * whereas the template version uses only 64 bytes of RAM (stack only).
 */

int main() {
  std::cout << "01. INTERFACE PATTERN COMPARISON" << std::endl;
  {
    using namespace oo;
    Renderer r(100,300,50,250);
    std::shared_ptr rect = std::make_shared<Rectangle>(60,40);
    std::shared_ptr circ = std::make_shared<Circle>(30);
    std::shared_ptr sqr = std::make_shared<Square>(40);

    std::cout << "OO mechanism:-" << std::endl;
    r.draw(rect);
    r.draw(circ);
    r.draw(sqr);

    std::size_t rSz = sizeof(r);
    std::size_t rectPtrSz = sizeof(rect);
    std::size_t circPtrSz = sizeof(circ);
    std::size_t sqrPtrSz = sizeof(sqr); 
    std::size_t rectSz = sizeof(*rect);
    std::size_t circSz = sizeof(*circ);
    std::size_t sqrSz = sizeof(*sqr); 
    std::cout << "Size of renderer: " << rSz << std::endl;
    std::cout << "Size of rect: " << rectPtrSz << " (pointer size)" << std::endl;
    std::cout << "Size of circ: " << circPtrSz << " (pointer size)" << std::endl;
    std::cout << "Size of sqr: " << sqrPtrSz << " (pointer size)" << std::endl;
    std::cout << "Size of *rect: " << rectSz << " (vtable pointer size + width + height)" << std::endl;
    std::cout << "Size of *circ: " << circSz << " (vtable pointer size + radius)" << std::endl;
    std::cout << "Size of *sqr: " << sqrSz << " (vtable pointer size + width)" << std::endl;
    std::cout << "TOTAL MEMORY USE: " << (rSz + rectPtrSz + circPtrSz + sqrPtrSz + rectSz + circSz + sqrSz) << " bytes" << std::endl;
  }
  {
    using namespace templated;
    Renderer r(100,300,50,250);
    Rectangle rect(60,40);
    Circle circ(30);
    Square sqr(40);

    std::cout << "Template mechanism:-" << std::endl;
    r.draw(rect);
    r.draw(circ);
    r.draw(sqr);

    std::size_t rSz = sizeof(r);
    std::size_t rectSz = sizeof(rect);
    std::size_t circSz = sizeof(circ);
    std::size_t sqrSz = sizeof(sqr); 
    std::cout << "Size of renderer: " << rSz << std::endl;
    std::cout << "Size of rect: " << rectSz << " (width + height only)" << std::endl;
    std::cout << "Size of circ: " << circSz << " (radius only)" << std::endl;
    std::cout << "Size of sqr: " << sqrSz << " (width only)" << std::endl;
    std::cout << "TOTAL MEMORY USE: " << (rSz + rectSz + circSz + sqrSz) << " bytes" << std::endl;
  }

  return 0;
}