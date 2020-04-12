#include "linkedlist.hpp"
#include <iostream>
#include <memory>


template <typename T>
void Linkedlist<T>::insert(T data, std::size_t pos)
{
  if(pos > list_size){
    std::cerr << "Memory location is not accessible" << std::endl;
    std::exit(EXIT_FAILURE);
  }

  /* Allocating memory for the Node data type */
  std::allocator<Node> mem;
  Node *temp_node_1 = mem.allocate(1);

  temp_node_1->data = data;
  temp_node_1->next = nullptr;

  /* Insert at the 0th posision */
  if(pos == 0){
    temp_node_1->next = head;
    head = temp_node_1;
    list_size ++;
    return;
  }

  Node *temp_node_2 = head;
  /* Go to pos - 1 */
  for(std::size_t i = 0; i < pos - 1; i++)
    temp_node_2 = temp_node_2->next;
  /* Create a first new link between the new one and the existing one in pos */
  /* It breaks the link between the one in (pos-1) and the existing one in pos */
  temp_node_1->next = temp_node_2->next;
  /* Create a second new link between the one in (pos-1) and the new one */
  temp_node_2->next = temp_node_1;
  list_size ++;
}

template <typename T>
void Linkedlist<T>::print()
{
  Node *temp_node = head;
  while(temp_node != nullptr){
    std::cout << temp_node->data << ",";
    temp_node = temp_node->next;
  }
  std::cout << std::endl;
}


template <typename T>
void Linkedlist<T>::remove(std::size_t pos)
{
  if(pos >= list_size){
    std::cerr << "Memory location is not accessible" << std::endl;
    std::exit(EXIT_FAILURE);
  }

  Node *temp_node_1 = head;
  /* Allocating memory for the Node data type */
  std::allocator<Node> mem;
  Node *temp_node_2 = mem.allocate(1);

  if(pos == 0){
    head = temp_node_1->next;
    free(temp_node_1);
    list_size --;
    return;
  }

  for(std::size_t i = 0; i < pos - 1; i++)
    temp_node_1 = temp_node_1->next;

  temp_node_2 = temp_node_1->next;
  temp_node_1->next = temp_node_2->next;
  mem.deallocate(temp_node_2, 1);
  list_size --;

}

template <typename T>
T Linkedlist<T>::at(std::size_t pos)
{
  if(pos >= list_size){
    std::cerr << "Out of bound" << std::endl;
    std::exit(EXIT_FAILURE);
  }

  Node *temp_node = head;

  for(std::size_t i = 0; i < pos; i++)
    temp_node = temp_node->next;

  return temp_node->data;
}

int main()
{
  Linkedlist<int> l_list;
  l_list.insert(10, 0);
  l_list.insert(20, 1);
  l_list.insert(32, 2);

  l_list.print();
  l_list.insert(40, 3);

  l_list.print();
  l_list.remove(3);
  l_list.print();
  std::cout << l_list.size() << std::endl;



//   l_list.insert(20, node);
// 

  return 0;
}
