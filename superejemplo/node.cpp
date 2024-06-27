#include "node.h"

PNode &push(PNode &head, Student const &st)
{
  if (!head)
  {
    head = make_shared<Node>(Node{st, nullptr});
    return head;
  }

  auto it = head;
  while (it->next)
  {
    it = it->next;
  }

  PNode node = make_shared<Node>(Node{st, nullptr});
  it->next = node;

  return head;
}

void forEach(PNode const &head, LambdaForEach const &f)
{
  auto it = head;
  while (it)
  {
    f(it->data);
    it = it->next;
  }
}
