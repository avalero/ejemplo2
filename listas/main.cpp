#include <memory>
#include <iostream>
#include <functional>
#include <vector>
#include <cstdlib> // For srand() and rand()
#include <ctime>   // For time()

using namespace std;

// Generate a random string of 5 characters
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
P_Node<T> push_in_order(P_Node<T> first, T const &data)
{
  auto it = first;
  if (first->data < data)
  {
    P_Node<T> nNode = make_shared<Node<T>>(Node<T>{data, first, uuid()});
    first = nNode;
    return first;
  }
  while (it->next)
  {
    if (it->next->data < data)
    {
      it = it->next;
    }
    else
    {
      P_Node<T> nNode = make_shared<Node<T>>(Node<T>{data, it->next, uuid()});
      it->next = nNode;
      return first;
    }
  }
  P_Node<T> nNode = make_shared<Node<T>>(Node<T>{data, nullptr, uuid()});
  it->next = nNode;
  return first;
}

template <typename T>
P_Node<T> push_back(P_Node<T> first, T const &data)
{
  auto it = first;

  while (it->next)
  {
    it = it->next;
  }
  P_Node<T> nNode = make_shared<Node<T>>(Node<T>{data, nullptr, uuid()});
  it->next = nNode;
  return first;
}

template <typename T>
P_Node<T> push(P_Node<T> first, T const &data, bool inOrder = false)
{
  if (inOrder)
  {
    return push_in_order(first, data);
  }
  else
  {
    return push_back(first, data);
  }
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
  {
    head = head->next;
    return;
  }

  auto it = head;
  while (it->next && it->next->id != id)
  {
    it = it->next;
  }
  if (it->next)
  {
    it->next = it->next->next;
  }
}

struct Person
{
  string nombre;
  string telefono;
};

bool operator<(Person const &p1, Person const &p2)
{
  return (p1.nombre < p2.nombre);
}

bool operator>(Person const &p1, Person const &p2)
{
  return (p1.nombre > p2.nombre);
}

bool operator==(Person const &p1, Person const &p2)
{
  return (p1.nombre == p2.nombre && p1.telefono == p2.telefono);
}

void showByName(P_Node<Person> first)
{
  string name;
  cout << "Introduce nombre: ";
  getline(cin, name);
  auto result = filter<Person>(first, [name](P_Node<Person> p)
                               { return p->data.nombre.find(name) != string::npos; });
  cout << "\n-----------------------------------------------------------------------\n";
  for (auto const &p : result)
  {
    cout << "|\t" << p->id << ":\t" << p->data.nombre << "\t" << p->data.telefono << endl;
  }
  cout << "-----------------------------------------------------------------------\n";
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
    first = push<Person>(first, {nombre, telefono}, true);
  }
}

void removeById(P_Node<Person> &first)
{
  string id;
  cout << "Introduce id: ";
  getline(cin, id);
  remove<Person>(first, id);
}

void clearScreen()
{
  // This will clear the console screen on Unix-based systems
  cout << "\033[2J\033[1;1H";
}

int main()
{
  // Initialize seed
  srand(static_cast<unsigned>(time(0)));

  P_Node<Person> head = nullptr;

  int option{0};
  while (true)
  {
    if (option != 0)
    {
      cout << "\nPulsa enter para continuar... ";
      cin.get();
    }

    clearScreen();

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
