# manager-tpl

This example uses templates and a vector of a variant to allow multiple instances of comparable types in the device manager class.

This aims to be an improvement over the OO (Object Orientated) version of the same sample.

Binary size: 65024 (64K) Debug, 25088 (24K) Release, both Windows

## Pros

- API much more logical and idiomatic
- Avoidance of std::shared_ptr and all the complexity that brings
- All allocation is on the stack, not the heap
- Three times as fast as OO alternative
  - Allocation is quicker than the OO variant BUT ONLY IF you use vector.reserve before doing large numbers of inserts
  - Find is quicker than the OO variant
- Slightly smaller application binary on Windows in RELEASE mode only

## Cons

- Gotta understand templates
- If using multiple types in the manager with vastly different memory sizes, you'll pay the cost for num_elements * largest_type.
- Use of templates means you reveal the internal implementation of the manager class
- Can't maintain ABI compatibility as per shared libraries
- Around 4.5K larger application binary on Windows in DEBUG mode only

## Performance comparison

Timings without vector reservation, DEBUG mode:-

```sh
D:\git\cppeval\build\manager-oo>"D:\git\cppeval\build\manager-oo\manager-oo.exe"
Creation progress:   ........................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................
Insert completed in 1.47966 seconds
Find by ID progress: ....................................................................................................
Found 100 people by ID
Find completed in 6.59012 seconds

D:\git\cppeval\build\manager-oo>"D:\git\cppeval\build\manager-tpl\manager-tpl.exe"
Creation progress:   ........................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................
Insert completed in 2.52227 seconds
Find by ID progress: ....................................................................................................
Found 100 people by ID
Find completed in 9.5479 seconds
```

Timings with vector reservation, DEBUG mode:-

```sh
D:\git\cppeval\build\manager-oo>"D:\git\cppeval\build\manager-oo\manager-oo.exe"
Creation progress:   ........................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................
Insert completed in 1.3615 seconds
Find by ID progress: ....................................................................................................
Found 100 people by ID
Find completed in 6.51742 seconds

D:\git\cppeval\build\manager-oo>"D:\git\cppeval\build\manager-tpl\manager-tpl.exe"
Creation progress:   ........................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................
Insert completed in 1.16822 seconds
Find by ID progress: ....................................................................................................
Found 100 people by ID
Find completed in 4.61661 seconds
```

In RELEASE mode with vector preallocation:-

```sh
D:\git\cppeval\build\manager-oo>"D:\git\cppeval\build\manager-oo\manager-oo.exe"
Creation progress:   ........................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................
Insert completed in 0.2153 seconds
Find by ID progress: ....................................................................................................
Found 100 people by ID
Find completed in 1.15586 seconds

D:\git\cppeval\build\manager-oo>"D:\git\cppeval\build\manager-tpl\manager-tpl.exe"
Creation progress:   ........................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................
Insert completed in 0.072527 seconds
Find by ID progress: ....................................................................................................
Found 100 people by ID
Find completed in 0.564873 seconds
```