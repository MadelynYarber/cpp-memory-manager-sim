#ifndef LIST_HPP
#define LIST_HPP

#include "List.h"
using namespace cop4530;



    //CONST ITERATOR FUNCTIONS

        template <typename T>
        List<T>::const_iterator::const_iterator() : current(nullptr)
        { }
        //In Slides he has const_iterator() : current{ nullptr }
        //{}

        template <typename T>
        const T& List<T>::const_iterator::operator*() const 
        { return retrieve();}

        template <typename T>
        typename List<T>::const_iterator& List<T>::const_iterator::operator++()
        {
        current = current->next;
        return *this;
    
        }

        template <typename T>
        typename List<T>::const_iterator List<T>::const_iterator::operator++(int)
        {
        const_iterator old = *this;
        ++( *this );
        return old;
        }
       

        //error
        template <typename T>
        typename List<T>::const_iterator& List<T>::const_iterator::operator--()
        {
            current = current->prev;
            return *this;
        }

        template <typename T>
        typename List<T>::const_iterator List<T>::const_iterator::operator--(int)
        {
            const_iterator old = *this;
            -- ( *this );
            return old;
        }

        template <typename T>
        bool List<T>::const_iterator::operator == ( const const_iterator & rhs ) const
        { return current == rhs.current; }

        template <typename T>
        bool List<T>::const_iterator::operator!= ( const const_iterator & rhs ) const
        { return !( *this == rhs ); }

         template <typename T>
        const T* List<T>::const_iterator::operator->() const 
        {
            return &(current->data);
        }

        //THESE NEXT FOUR ARE SUPPOSED TO BE PROTECTED
        template <typename T>
        typename List<T>::const_iterator::Node *current;  

        template <typename T>
        T& List<T>::const_iterator::retrieve() const
        { return current-> data; }

        template <typename T>
        List<T>::const_iterator::const_iterator( Node *p ) : current{ p }
        { }

        //friend class List<T>;

    //~~~~~~~~~~~~~~~

        //MEMBER FUNCTIONS OF NESTED ITERATOR CLASS
        template <typename T>
        List<T>::iterator::iterator()
        { }


        template <typename T>
        T& List<T>::iterator::operator* ( )
        { return const_iterator::retrieve(); }

        template <typename T>
        const T& List<T>::iterator::operator* ( ) const
        { return const_iterator::operator*(); }
    
        template <typename T>
        typename List<T>::iterator& List<T>::iterator::operator++()
        {
            this->current = this->current->next;
            return *this;
        }

        template <typename T>
        typename List<T>::iterator List<T>::iterator::operator++ ( int )
        {
            iterator old = *this;
            ++( *this );
            return old;
        }

        //implemented operator-- myself
        template <typename T>
        typename List<T>::iterator& List<T>::iterator::operator--()
        {
            this->current = this->current->prev;
            return *this;
        }

        template <typename T>
        typename List<T>::iterator List<T>::iterator::operator-- ( int )
        {
            iterator old = *this;
            --( *this );
            return old;
        }

        //protected:  
        template <typename T>
        List<T>::iterator::iterator( Node *p ) : const_iterator{ p }
        { }

        template <typename T>
        T* List<T>::iterator::operator->() {
        return &this->current->data; // Return a pointer to the current node's data
        }

        template <typename T>
        const T* List<T>::iterator::operator->() const {
        return &this->current->data; // Return a pointer to the current node's data (const version)
        }
        //friend class List<T>;

    //~~~~~~~~~~~~~ 

//MEMBER FUNCTIONS OF LIST
    template <typename T>
    List<T>::List()
    { init (); }

    template <typename T>
    List<T>::~List()
    {
        clear();
        delete head;
        delete tail;
    }

    template <typename T>
    List<T>::List(const List & rhs)
    {
        init();
        for(auto & x : rhs)
            push_back(x);
    }

    template <typename T>
    const List<T>& List<T>::operator=(const List& rhs)
    {
        List copy = rhs;
        std::swap( *this, copy );
        return *this;
    }

    template <typename T>
    List<T>::List(List && rhs) : theSize{ rhs.theSize}, head{rhs.head}, tail{rhs.tail}
    {
        rhs.theSize = 0;
        rhs.head = nullptr;
        rhs.tail = nullptr;
    }

    template <typename T>
    List<T>& List<T>::operator= ( List && rhs)
    {
        std::swap(theSize, rhs.theSize);
        std::swap(head, rhs.head);
        std::swap(tail, rhs.tail);

        return *this;
    }

    template <typename T>
    typename List<T>::iterator List<T>::begin()
    { return iterator(head->next);}

    template <typename T>
    typename List<T>::const_iterator List<T>::begin() const
    { return const_iterator(head->next);}

    template <typename T>
    typename List<T>::iterator List<T>::end()
    { return iterator(tail);}

    template <typename T>
    typename List<T>::const_iterator List<T>::end() const
    { return const_iterator(tail);}

    template <typename T>
    int List<T>::size() const
    { return theSize; }

    //editted implimentation
    template <typename T>
    bool List<T>::empty() const
    { 
        //slides just says return size()==0, just hw says to return true or false
        if(size()==0)
            return true; 
        else
            return false;
    } 

    template <typename T>
    void List<T>::clear()
    {
        while ( !empty())
            pop_front();
    }

    template <typename T>
    T& List<T>::front()
    { 
        return *begin(); 
    }

    template <typename T>
    const T& List<T>::front() const
    { return *begin(); }

    template <typename T>
    T& List<T>::back()
    { return *--end(); }

    template <typename T>
    const T& List<T>::back() const
    { return *--end(); }

    template <typename T>
    void List<T>::push_front( const T & x )
    { insert( begin(), x); }

    template <typename T>
    void List<T>::push_back(const T & x)
    { insert(end(), x); }

    template <typename T>
    void List<T>::push_front( T && x)
    { insert(begin(), std::move(x)); }

    template <typename T>
    void List<T>::push_back( T && x ) 
    { insert( end(), std::move(x)); }

    template <typename T>
    void List<T>::pop_front()
    { erase( begin()); }

    template <typename T>
    void List<T>::pop_back()
    { 
        erase(--end());
    }

    template <typename T>
    typename List<T>::iterator List<T>::insert(iterator itr, const T& val)
    {
        Node *p = itr.current;
        ++theSize;
        return iterator(p->prev->next = new Node{ val, p->prev, p});
    }

    template <typename T>
    typename List<T>::iterator List<T>::insert(iterator itr, T && val)
    {
        Node *p = itr.current;
        ++theSize;
        return iterator(p->prev = p->prev->next = new Node{std::move(val), p->prev, p});
    }

    template <typename T>
    typename List<T>::iterator List<T>::erase(iterator itr)
    {
        Node *p = itr.current;
        iterator retVal(p->next);
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        --theSize;
        return retVal;
    }

    template <typename T>
    typename List<T>::iterator List<T>::erase(iterator start, iterator end)
    {
        for(iterator itr = start; itr != end; )
            itr = erase(itr);

        return end;    
    }
    

  template <typename T>
    void List<T>::init()
    {
        theSize = 0;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }

    template <typename T>
    List<T>::List(int num, const T & val) : theSize(num), head(nullptr), tail(nullptr) 
    {
        if (num <= 0) return; 

        head = new Node{val}; 
        tail = head;          
        
        for (int i = 1; i < num; ++i) 
    {
            Node* newNode = new Node{val};
            tail->next = newNode;          
            newNode->prev = tail;         
            tail = newNode;                
    }
}


    template <typename T>
    List<T>::List(const_iterator start, const_iterator end) : theSize(0), head(nullptr), tail(nullptr) 
    {
        for (auto itr = start; itr != end; ++itr) 
        {
        // Push back each element from the range [start, end)
        push_back(*itr);
        }
    }

    template <typename T>
    void List<T>::reverse() 
    {
    //if (empty()) return;
    Node* current = head; // Start from the head

        for (; current != nullptr; ) 
        {
            std::swap(current->prev, current->next); 
            current = current->prev;
        }
            std::swap(head, tail);
    }

    template <typename T>
    void List<T>::remove(const T & val) 
    {
        for (Node* current = head; current != nullptr; ) 
        {
            if (current->data == val) 
            {
            Node* nodeToDelete = current;

            // Update pointers to bypass the node to delete
            if (nodeToDelete->prev) 
            {
                nodeToDelete->prev->next = nodeToDelete->next; // Link previous to next
            } 
            else 
            {
                head = nodeToDelete->next; // Update head if it's the first node
            }

            if (nodeToDelete->next) 
            {
                nodeToDelete->next->prev = nodeToDelete->prev; // Link next to previous
            } 
            else 
            {
                tail = nodeToDelete->prev; // Update tail if it's the last node
            }

            current = nodeToDelete->next; // Move to the next node
            delete nodeToDelete; // Delete the current node
            --theSize; // Decrease the size of the list
        } 
        else 
        {
            current = current->next; // Move to the next node
        }
    }
}


template <typename T>
void List<T>::print(std::ostream &os, char ofc) const {
    Node* current = head; // Start from the head
    while (current != nullptr) {
        os << current->data; // Print the current node's data
        current = current->next; // Move to the next node
        if (current != nullptr) { // If not the last element, print the delimiter
            os << ofc;
        }
    }
}



template <typename T>
bool operator==(const List<T> & lhs, const List<T> & rhs) {
    // First, check if both lists have the same size
    if (lhs.size() != rhs.size()) {
        return false; // Not equal if sizes differ
    }

    // Use iterators to compare elements
    typename List<T>::const_iterator it1 = lhs.begin();
    typename List<T>::const_iterator it2 = rhs.begin();

    while (it1 != lhs.end() && it2 != rhs.end()) {
        if (*it1 != *it2) {
            return false; // Elements are not equal
        }
        ++it1; // Move to the next element in lhs
        ++it2; // Move to the next element in rhs
    }

    return true; // Lists are equal
}

template <typename T>
bool operator!=(const List<T> & lhs, const List<T> & rhs) {
    return !(lhs == rhs); // Use the equality operator to determine inequality
}

template <typename T>
std::ostream& operator<<(std::ostream & os, const List<T> & l) {
    l.print(os); // Call the print method of the List class
    return os;   // Return the output stream
}


    //};


    //reverse function, for loop through the whole thing, swap (prev, next) then outside of for loop swap head and tail

#endif
