#include <memory>
#include <iostream>
#include <functional>

using namespace std;

struct Node;

using P_Node = shared_ptr<Node>;

int uuid()
{
  return rand() % 10000;
}

struct Data
{
  int value;
  int id = uuid();
};

struct Node
{
  Data data;
  shared_ptr<Node> left;
  shared_ptr<Node> right;
};

P_Node &push(P_Node &head, Data data)
{
  if (!head)
  {
    head = make_shared<Node>(Node{data, nullptr, nullptr});
    return head;
  }

  if (head->data.id > data.id)
  {
    head->left = push(head->left, data);
    return head;
  }
  else
  {
    head->right = push(head->right, data);
    return head;
  }
}

P_Node find(P_Node const &head, int id)
{
  if (!head)
    return nullptr;

  if (head->data.id == id)
    return head;

  if (head->data.id > id)
  {
    return find(head->left, id);
  }
  else
  {
    return find(head->right, id);
  }
}

int main(void)
{
  srand(time(0));
  shared_ptr<Node> head;
  Data a{3};
  Data b{2};
  Data c{4};
  Data d{1};

  head = push(head, a);
  push(head, b);
  push(head, c);
  push(head, d);

  auto x = find(head, c.id);
  cout << c.id << endl;
  cout << x->data.id << endl;
  cout << c.value << endl;
  cout << x->data.value << endl;
  return 0;
}