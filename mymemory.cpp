

//#ifndef MYMEMORY_CPP
//#define MYMEMORY_CPP

#include "mymemory.h"
#include "mymemoryblock.h"

    MyMemory::MyMemory(int num, int len)   
    {
        //resize(num, len);
        max_index = num - 1;
        block_size = len;

        for (int i = 0; i < num; ++i)
        {
           //MyMemoryBlock* block(i, len);
           //mlist.insert(block); 

           //mlist.insert(new MyMemoryBlock(i, len)); 

            mlist.push_back(new MyMemoryBlock(i, len));
        }

    }

    void MyMemory::resize(int num, int len) 
    {
        if (!mlist.empty()) 
        {
            mlist.clear();
        }

        for (int i = 0; i > num-1; ++i)
        {
           mlist.push_back(new MyMemoryBlock(i, len)); 
        }
    }

    //int MyMemory::getMaxIndex()
    //{
       // return max_index;
    //}

    //int MyMemory::getBlockSize() 
    //{
      //  return block_size;
    //}

    //int MyMemory::getCurrentBlocks()
    //{
      //  return mlist.size();
    //}

    //void MyMemory::allocate_mem(int len)
    //{
       // length -= len;
    //}

    int MyMemory::req_mem(int len)
    {
        for (auto i = mlist.begin(); i != mlist.end(); ++i)     
        {
            if ((*i) -> get_length() >= len) 
            {
            //CALLED allocate mem
                (*i) -> allocate_mem(len);
                int index = (*i) -> get_index(); 

            // If the block is now empty, remove it
                if ((*i) -> get_length() == 0)  
                {
                i = mlist.erase(i);
                }

             return index; // Return the index of the block
            }
        }
        return -1; // No suitable block found
    }

    //void MyMemory::free_mem(int len)
    //{
      //  length += len;
    //}
    

    bool MyMemory::release_mem(int ind, int len)
    {
        //ind specified the index of the block, len specifies the length 
        //if a memory black with index exists in mlist, "len" shoudl be added back to the length by calling fe

        if (ind < 0 || ind > max_index || len <= 0 || len > block_size)
           {
            return false;
           }   


        for (auto i = mlist.begin(); i != mlist.end(); ++i)     
        {
            if ((*i) -> get_index() == ind)
            {
                (*i) -> free_mem(len);
            }
            else
            {
                MyMemoryBlock* AddBlock = new MyMemoryBlock(ind, len);
                mlist.push_back(AddBlock);

            }


        }
        return true;
           
    }

    //void MyMemory::set_length(int len)
    //{
      //  length = len;
    //}

    void MyMemory::merge_mem()
    {
        for (auto i = mlist.begin(); i != mlist.end(); ++i) //took ++i out at the end
        {
            auto next_block = next(i);
            
            if (next_block != mlist.end())
            {
                int currentLength = (*i) -> get_length();
                int nextLength = (*next_block) -> get_length();
                if (currentLength + nextLength <= block_size)
                {
                    //error here
                //(*i) -> get_length() += (*next_block) -> get_length();
                (*i)->set_length((*i)->get_length() + (*next_block)->get_length());
                i = mlist.erase(next_block);
                }            
                else
                {
                    i++;
                }
            }    
            
        }
    }

    void MyMemory::dump()
    {
        cout << "in function dump()" << endl;
        if (mlist.empty())
        {
            cout << "Memory list is empty" << endl;
        }
        for (auto i = mlist.begin(); i != mlist.end(); ++i)
        {
            cout << "Index: " << (*i) -> get_index() << ", Length: " << (*i) -> get_length() << endl;        
        }
    }

    MyMemory::~MyMemory()
    {
        mlist.clear();
    }
    
//#endif
