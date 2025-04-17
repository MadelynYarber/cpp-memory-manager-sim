#ifndef MYMEMORYBLOCK_H
#define MYMEMORYBLOCK_H

#include <iostream>
#include <list>

class MyMemoryBlock     
{
    private:
    int index;
    int length;

    public:
    MyMemoryBlock(int, int);
    int get_length();
    int get_index();
    void set_length(int len);
    int allocate_mem(int len);
    void free_mem(int len);






};

//#include "mymemoryblock.cpp"
//#include "mymemory.hpp"
#endif