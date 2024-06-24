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
  string id;
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
  P_Node<T> nNode = make_shared<Node<T>>(Node<T>{data, nullptr, uuid()});
  it->next = nNode;
  return nNode;
}

template <typename T>
P_Node<T> push_r(P_Node<T> first, T const &data)
{
  if (first->next)
    return push_r<T>(first->next, data);

  P_Node<T> nNode = make_shared<Node<T>>(Node<T>{data, nullptr, uuid()});
  first->next = nNode;
  return nNode;
}

template <typename T>
void imprimir_elems(P_Node<T> first)
{
  auto it = first;
  while (it)
  {
    cout << it->id << ":\t" << it->data << endl;
    it = it->next;
  }
}

template <typename T>
void imprimir_recursivo(P_Node<T> p)
{
  if (p)
  {
    cout << p->id << ":\t" << p->data << endl;
    imprimir_recursivo<T>(p->next);
  }
}

template <typename T>
void forEach(P_Node<T> first, function<void(P_Node<T>)> f)
{
  auto it = first;
  while (it)
  {
    f(it);
    it = it->next;
  }
}

template <typename T>
void remove(P_Node<T> &head, string const &id)
{
  if (head->id == id)
    head = head->next;

  auto it = head;
  while (it->next->id != id)
  {
    it = it->next;
    if (it == nullptr)
      return;
  }
  it->next = it->next->next;
}

int main()
{

  // 1. Mostrar todos (id, nombre, telefon)
  // 2. Añadir (nombre, telefono)
  // 3. Borrar (por id)
  // 4. Buscar (por nombre) -> mostrar

  // intialize seed
  srand(time(0));

  P_Node<int> start = make_shared<Node<int>>(Node<int>{1, nullptr, uuid()});
  push(start, 23);
  push(start, 31);
  push(start, 45);
  cout << "Iterativo: " << endl;
  imprimir_elems<int>(start);

  cout << "\n\nRecursivo: " << endl;
  imprimir_recursivo<int>(start);

  cout << "\n\nFuncional: " << endl;
  forEach<int>(start, [](P_Node<int> p)
               { cout << p->id << ":\t" << p->data << endl; });
}