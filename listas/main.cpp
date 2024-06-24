#include <memory>

using namespace std;

template <typename T>
struct Node
{
  T data;
  shared_ptr<Node> next;
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

void imprimir_elems(P_Node first)
{
  // mostrar todos los datos // iterativo
}

void imprimir_recursivo(P_Node first)
{
  // mostrar todos los datos;
}

void forEach(P_Node first, /* funcion lambda*/)
{
  // hace lo que diga la f_lambda
}

int main()
{

  P_Node<int> start = make_shared<Node<int>>(Node<int>{1, nullptr});
  auto segundo = push(start, 23);
  auto tercero = push(segundo, 31);
  push(tercero, 45);
}