#include <memory>

using namespace std;

typedef shared_ptr<Node> P_Node;

struct Node
{
  int data;
  shared_ptr<Node> next;
};

P_Node push(P_Node first, int data)
{
  auto it = first;
  while (it->next)
  {
    it = it->next;
  }
  P_Node nNode = make_shared<Node>(Node{data, nullptr});
  it->next = nNode;
  return nNode;
}

P_Node push_r(P_Node first, int data)
{
  if (first->next)
    return push_r(first->next, data);

  P_Node nNode = make_shared<Node>(Node{data, nullptr});
  first->next = nNode;
  return nNode;
}

int main()
{

  P_Node start = make_shared<Node>(Node{1, nullptr});
  auto segundo = push(start, 23);
  auto tercero = push(segundo, 31);
  push(tercero, 45);
}