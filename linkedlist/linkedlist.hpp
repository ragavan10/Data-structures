#ifndef __LINKEDLIST_HPP__
#define __LINKEDLIST_HPP__

#include <cstddef>

template <typename T>
class Linkedlist{

  public:
    /**
     * Insert data into the linkedlist
     *
     * \param data The data to be pushed into the linkedlist
     * \param pos Which position to be in the linkedlist
    **/
    void insert(T data, std::size_t pos);

    /**
     * Print linkedlist
    **/
    void print();

    /**
     * Remove the nth elemnet from the linkedlist
     *
     * \param pos The elment to be removed from the linked list
    **/
    void remove(std::size_t pos);

    /**
     * Returns true if the linkedlist empty, false otherwise
    **/
    bool empty() { return ((list_size == 0) ? true : false); }

    /**
     * Returns the content of the node in the given  position
    **/
    T at(std::size_t pos);

    /**
     * Returns the size of the linkedlist 
    **/

    std::size_t size() { return list_size; }

  private:
    /**
      * Node data structure
      *
      * \param data holds content of the linkedlist
      * \param next Pointer to the next element in the linkedlist
      *
    **/
    struct Node{
      T data;
      Node* next;
    };

    Node *head = nullptr;
    std::size_t list_size = 0;

};

#endif //__linkedlist__
