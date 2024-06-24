#include <memory>
#include <iostream>
#include <functional>

using namespace std;

// generate random string of 5 chars
string uuid()
{
  string id = "";
  for (int i = 0; i < 5; i++)
  {
    id += 'a' + rand() % 26;
  }
  return id;
}

template <typename T>
struct Node
{
  T data;
  shared_ptr<Node> next;
  // string id;
};

template <typename T>
using P_Node = shared_ptr<Node<T>>;

template <typename T>
P_Node<T> push(P_Node<T> first, T const &data)
{
  auto it = first;
  while (it->next)
  {
    it = it->next;
  }
  P_Node<T> nNode = make_shared<Node<T>>(Node<T>{data, nullptr});
  it->next = nNode;
  return nNode;
}

template <typename T>
P_Node<T> push_r(P_Node<T> first, T const &data)
{
  if (first->next)
    return push_r<T>(first->next, data);

  P_Node<T> nNode = make_shared<Node<T>>(Node<T>{data, nullptr});
  first->next = nNode;
  return nNode;
}

template <typename T>
void imprimir_elems(P_Node<T> first)
{
  auto it = first;
  while (it)
  {
    cout << it->data << endl;
    it = it->next;
  }
}

template <typename T>
void imprimir_recursivo(P_Node<T> p)
{
  if (p)
  {
    cout << p;
    imprimir_recursivo<T>(p->next);
  }
}

template <typename T>
void forEach(P_Node<T> first, fuction<void(T)> f)
{
  auto it = first;
  while (it)
  {
    f(it->data);
    it = it->next;
  }
}

int main()
{

  P_Node<int> start = make_shared<Node<int>>(Node<int>{1, nullptr});
  auto segundo = push(start, 23);
  auto tercero = push(segundo, 31);
  push(tercero, 45);
}