#include <memory>
#include <iostream>
#include <functional>
#include <vector>

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
vector<P_Node<T>> filter(P_Node<T> first, function<bool(P_Node<T>)> f)
{
  vector<P_Node<T>> result;
  auto it = first;
  while (it)
  {
    if (f(it))
    {
      result.push_back(it);
    }
    it = it->next;
  }
  return result;
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

struct Person
{
  string nombre;
  string telefono;
};

void showByName(P_Node<Person> first)
{

  string name;
  cout << "Introduce nombre: ";
  getline(cin, name);
  auto result = filter<Person>(first, [name](P_Node<Person> p)
                               { return p->data.nombre.find(name) != -1; });
  cout << "\n-----------------------------------------------------------------------\n";
  for (auto const &p : result)
  {
    cout << "|\t" << p->id << ":\t" << p->data.nombre << "\t" << p->data.telefono << endl;
  }
  cout << "\n-----------------------------------------------------------------------\n";
}

void showAll(P_Node<Person> const &first)
{
  cout << "\n-----------------------------------------------------------------------\n";
  forEach<Person>(first, [](P_Node<Person> p)
                  { cout << "|\t" << p->id << ":\t" << p->data.nombre << "\t" << p->data.telefono << endl; });
  cout << "-----------------------------------------------------------------------\n";
}

void add(P_Node<Person> &first)
{
  string nombre;
  string telefono;
  cout << "Introduce nombre: ";
  getline(cin, nombre);
  cout << "Introduce telefono: ";
  getline(cin, telefono);
  if (first == nullptr)
  {
    first = make_shared<Node<Person>>(Node<Person>{{nombre, telefono}, nullptr, uuid()});
  }
  else
  {
    push<Person>(first, {nombre, telefono});
  }
}

void removeById(P_Node<Person> &first)
{
  string id;
  cout << "Introduce id: ";
  cin >> id;
  cin.ignore();
  remove<Person>(first, id);
}

int main()
{

  // intialize seed
  srand(time(0));

  // 1. Mostrar todos (id, nombre, telefon)
  // 2. Añadir (nombre, telefono)
  // 3. Borrar (por id)
  // 4. Buscar (por nombre) -> mostrar

  P_Node<Person> head = nullptr;

  int option{0};
  while (true)
  {
    // clear screen
    if (option != 0)
    {
      cout << "Pulsa enter para continuar... ";
      cin.get();
    }
    cout << "\033[2J\033[1;1H";
    cout << "╔════════════════════════════════════════════╗" << endl;
    cout << "║                 MENU PRINCIPAL             ║" << endl;
    cout << "╠════════════════════════════════════════════╣" << endl;
    cout << "║  1. Mostrar todos (id, nombre, telefono)   ║" << endl;
    cout << "║  2. Añadir (nombre, telefono)              ║" << endl;
    cout << "║  3. Borrar (por id)                        ║" << endl;
    cout << "║  4. Buscar (por nombre) -> mostrar         ║" << endl;
    cout << "║ -1. Salir                                  ║" << endl;
    cout << "╚════════════════════════════════════════════╝" << endl;
    cout << "Introduce una opción: ";
    cin >> option;
    cin.ignore();
    switch (option)
    {
    case 1:
      showAll(head);
      break;
    case 2:
      add(head);
      break;
    case 3:
      removeById(head);
      break;
    case 4:
      showByName(head);
      break;
    case -1:
      return 0;
    default:
      cout << "Opción no válida" << endl;
    }
  }
}