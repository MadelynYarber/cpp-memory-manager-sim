# Memory Management Simulator
A command-line program that simulates memory block allocation, deallocation, and merging using custom C++ classes. Includes an interactive menu and a templated doubly-linked list implementation.

---
## Features

- Dynamic memory block allocation
- Block deallocation and merging
- Interactive user menu
- Custom `List<T>` container with iterators
- Memory dump view

---
## Key Files

- `MyMemory`, `MyMemoryBlock`: Represent memory and logic
- `List.hpp`: Templated doubly linked list
- `mem_manager.cpp`: Interactive CLI runner

---
## How to Run

```bash
make
./mem_manager
