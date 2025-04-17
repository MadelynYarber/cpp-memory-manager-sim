//#ifndef MYMEMORYBLOCK_HPP
//#define MYMEMORYBLOCK_HPP

#include "mymemoryblock.h"

    MyMemoryBlock::MyMemoryBlock(int ind = 0, int len = 0)
    {
        index = ind;
        length = len;
    }

    int MyMemoryBlock::get_length()
    {
        return length;
    }

    int MyMemoryBlock::get_index()
    {
        return index;
    }
    
    int MyMemoryBlock::allocate_mem(int len)
    {
        if (len > length)  
        {
            return -1;
        }
        else
        {
            length -= len;
            return len;
        }
    }

    void MyMemoryBlock::set_length(int len)
    {
        length = len;
    }

    void MyMemoryBlock::free_mem(int len)
    {
        length += len;
    }
    



    //#endif