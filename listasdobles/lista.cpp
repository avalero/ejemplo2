#include "lista.h"
#include <stdexcept>

string uuid()
{
  string id = "";
  for (int i = 0; i < 5; i++)
  {
    id += 'a' + rand() % 26;
  }
  return id;
}

P_Node insertBefore(P_Node const &it, int data)
{
  P_Node node = make_shared<Node>(Node{uuid(), data, it, it->prev});
  it->prev->next = node;
  it->prev = node;
  return node;
}

/**
 * Function to add a new data at the end of the list
 * @param head first node of the list
 * @param data the data of the new node
 * @return first node of the list
 */
P_Node push_back(P_Node const &head, int data)
{
  if (!head)
  {
    P_Node node = make_shared<Node>(Node{uuid(), data, nullptr, nullptr});
    return node;
  }

  auto it = head;
  while (it->next)
  {
    it = it->next;
  }

  // estoy en el ultimo
  P_Node node = make_shared<Node>(Node{uuid(), data, nullptr, it});
  it->next = node;

  return head;
}

P_Node push_front(P_Node const &head, int data)
{
  if (!head)
  {
    P_Node node = make_shared<Node>(Node{uuid(), data, nullptr, nullptr});
    return node;
  }

  P_Node node = make_shared<Node>(Node{uuid(), data, head, nullptr});
  return node;
}

P_Node push_at(P_Node const &head, int data, int pos)
{
  if (pos < 0)
    throw std::out_of_range("Invalid position. Must be greater or equal than 0");
  if (pos == 0)
    return push_front(head, data);

  if (!head && pos != 0)
    throw std::out_of_range("Invalid position");

  // sabemos que hay head y que la pos > 0
  auto it = head;
  int index{0};
  while (it->next)
  {
    index++;
    it = it->next;
    if (pos == index)
    {
      P_Node node = insertBefore(it, data);
      return head;
    }
  }
  throw std::out_of_range("Invalid position. Greater than list.");
}
P_Node push_in_order(P_Node const &head, int data, bool asc)
{
  if (!head)
  {
    P_Node node = make_shared<Node>(Node{uuid(), data, nullptr, nullptr});
    return node;
  }

  auto it = head;
  while (it->next)
  {
    auto condition = asc ? it->next->data < data : it->next->data > data;
    if (condition)
    {
      it = it->next;
    }
    else
    {
      P_Node node = insertBefore(it, data);
      return head;
    }
  }
  push_back(head, data);
  return head;
}