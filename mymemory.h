#ifndef MYMEMORY_H
#define MYMEMORY_H

#include <iostream>
#include <list>
#include "List.h"
#include "mymemoryblock.h"

using namespace std;

class MyMemory     
{
    private:
    //double check vector
    list<MyMemoryBlock*> mlist;
    int max_index;
    int block_size;
    int number;
    int length;


    public:
    //int length;
    //MyMemory(int num = 0, int len = 0);
    MyMemory(int num, int len);
    int getMaxIndex();
    int getBlockSize();
    int getCurrentBlocks();

    void set_length(int len);
    void allocate_mem(int len);
    void free_mem(int len);
    void resize(int num = 100, int len = 100);
    int req_mem(int len);
    bool release_mem(int ind, int len);
    void merge_mem();
    void dump();
    ~MyMemory();
    
};

//#include "mymemory.cpp"
#endif