#include "oo.h"
#include "tpl.h"

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