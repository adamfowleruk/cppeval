# oo-to-tpl

A comparison of Object Orientated classical approaches (Using dynamic polymorphism) with
modern C++17's template equivalent approach (Using static polymorphism).

## Pros

- Less memory use as no vtables or shared_ptrs
- Faster execution as we're not following pointers
- Use of Stack memory only, not the heap

## Cons

- Depending on your platform you may prefer to use the heap for large numbers of temporary objects (You can still do this though)
- Templates require defining template classes in a header file. This will be made simpler in C++20 due to modules

## Runtime output

On Windows 10 with CLang 10.0.0 for MSVC with VS Community 2019 Release, Release Build:-

```
D:\git\cppeval\build\oo-to-tpl>"D:\git\cppeval\build\oo-to-tpl\oo-to-tpl.exe"
01. INTERFACE PATTERN COMPARISON
OO mechanism:-
I've just drawn a shape from (100,50) to (160,90)
I've just drawn a shape from (100,50) to (160,110)
I've just drawn a shape from (100,50) to (140,90)
Size of renderer: 32
Size of rect: 16 (pointer size)
Size of circ: 16 (pointer size)
Size of sqr: 16 (pointer size)
Size of *rect: 24 (vtable pointer size + width + height)
Size of *circ: 16 (vtable pointer size + radius)
Size of *sqr: 16 (vtable pointer size + width)
TOTAL MEMORY USE: 136 bytes
Template mechanism:-
I've just drawn a shape from (100,50) to (160,90)
I've just drawn a shape from (100,50) to (160,110)
I've just drawn a shape from (100,50) to (140,90)
Size of renderer: 32
Size of rect: 16 (width + height only)
Size of circ: 8 (radius only)
Size of sqr: 8 (width only)
TOTAL MEMORY USE: 64 bytes
```