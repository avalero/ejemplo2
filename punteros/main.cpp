#include <memory>
#include <iostream>
#include <vector>
using namespace std;

struct Person
{
  string name;
  int age;
  bool underAge;
};

vector<shared_ptr<Person>> filtrarMayoresDeEdad(vector<shared_ptr<Person>> const &p)
{
  vector<shared_ptr<Person>> result;
  for (auto const &persona : p)
  {
    if (persona->age >= 18)
      result.push_back(persona);
  }

  return result;
}

int main()
{

  vector<shared_ptr<Person>> personas;

  personas.push_back(make_shared<Person>(Person{"Alberto", 21, true}));
  personas.push_back(make_shared<Person>(Person{"Alberto2", 16, true}));
  personas.push_back(make_shared<Person>(Person{"Alberto3", 20, true}));
  personas.push_back(make_shared<Person>(Person{"Alberto4", 15, true}));
  personas.push_back(make_shared<Person>(Person{"Alberto5", 14, true}));
  personas.push_back(make_shared<Person>(Person{"Alberto6", 84, true}));

  auto mayores_edad = filtrarMayoresDeEdad(personas);

  for (auto const &p : mayores_edad)
  {
    p->underAge = false;
  }

  for (auto const &p : personas)
  {
    cout << "Nombre: " << p->name << "\tEdad: " << p->age << "\tUnder Age: " << p->underAge << endl;
  }
}
