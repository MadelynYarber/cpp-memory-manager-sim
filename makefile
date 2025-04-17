CXX=g++
CXXFLAGS=-Wall -pedantic

test_list.x: List.hpp List.h test_list.cpp
	$(CXX) $(CXXFLAGS) -o $@ test_list.cpp

proj2.x: List.hpp List.h mem_manager.o mymemoryblock.o mymemory.o
	$(CXX) $(CXXFLAGS) -o $@ mem_manager.o mymemoryblock.o mymemory.o

mymemory.o : List.hpp List.h mymemory.h mymemory.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ mymemory.cpp

.SUFFIXES: .x

.PHONY : clean

clean:
	rm -f *.o *.x core.*

%.x : %.c
	$(CC) -o $@ $<
%.x : %.cpp
	$(CXX) -o $@ $<
