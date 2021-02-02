# Adam's C++ Evaluation playground

I've often thought "I wonder what would happen if I did it this way instead"
but never really got around to trying it out. This happens a lot in modern C++.

In C++ there are 'classical' ways of doing things - object orientated design,
shared pointers and such, and thoroughly 'modern' ways of doing things.
Many of these modern ways have only really become available since C++17.

The samples in this repository compare and contrast different approaches to
solve the same problems, and provide CPU, time and memory measurable metrics
as well as API design, usability, maintainability and other project
maintainer considerations in the alternatives.

## Managing a container with multiple types of member

A common pattern is that of managing the creation and lifecycle of a set
of objects whilst allowing other parts of the programme to request the creation
of them, find them by a comparator, and potentially modify them due to
external data changes.

In many of these cases we will deal with just one type of thing, but we may
well find that we manage subclasses of a particular type.

Ideally the 'manager' will not be a mere encapsulation of a container type,
but rather have its own logic and pro-actively maintain the lifecycle of these
referenced objects over time, based perhaps on activity (like a cache or view
of a subsystem).

This sample provides two example implementations:-

- [manager-oo](manager-oo/README.md) - Object Orientated manager class, with a base class and one derived class. Uses shared pointers as a result, and thus heap allocation
- [manager-tpl](manager-tpl/README.md) - Variadic template and variant based implementation that uses references only and thus stack allocation

Stack allocation is particularly important in embedded C++ as many devices do not implement a heap.

The template/variant version outperforms the 'classical' object orientated 
version in terms of overall speed, is more idiomatically obvious for a developer,
and has a slightly smaller application binary.

TODO: Determine RAM usage results using Valgrind

