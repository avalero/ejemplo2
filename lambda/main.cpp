#include <functional>
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

struct Person
{
  string name;
  int edad;
};

typedef vector<shared_ptr<Person>> vP;
typedef function<void(shared_ptr<Person>)> voidFunPerson;
typedef function<bool(shared_ptr<Person>)> boolFunPerson;
typedef function<shared_ptr<Person>(shared_ptr<Person>)> PersonFunPerson;

typedef vector<int> vi;
typedef function<void(int)> flambda;
typedef function<bool(int)> boollambda;

void forEachPersons(vP const &v, voidFunPerson const &f)
{
  for (auto const &elem : v)
  {
    f(elem);
  }
}
vP filterPersons(vP const &v, boolFunPerson const &f)
{
  vP result;
  for (auto const &elem : v)
  {
    if (f(elem))
      result.push_back(elem);
  }
  return result;
}
bool somePersons(vP const &v, boolFunPerson const &f)
{
  for (auto const &elem : v)
  {
    if (f(elem))
      return true;
  }
  return false;
}
bool everyPersons(vP const &v, boolFunPerson const &f)
{
  for (auto const &elem : v)
  {
    if (!f(elem))
      return false;
  }
  return true;
}
vP transformPerson(vP const &v, PersonFunPerson const &f)
{
  vP result;
  for (auto elem : v)
  {
    // result.push_back((f(elem)));
    shared_ptr<Person> copiaDeLaPersona = make_shared<Person>(*elem);
    result.push_back(f(copiaDeLaPersona));
  }
  return result;
}

int main()
{
  vP personas{
      make_shared<Person>(Person{"Alberto", 19}),
      make_shared<Person>(Person{"José", 12}),
      make_shared<Person>(Person{"Juan", 42}),
      make_shared<Person>(Person{"Luis", 13}),
      make_shared<Person>(Person{"María", 65}),
      make_shared<Person>(Person{"Lucía", 19})};

  forEachPersons(personas, [](shared_ptr<Person> p)
                 { cout << p->name << endl; });

  forEachPersons(personas, [](shared_ptr<Person> p)
                 { if(p->edad >= 18) cout << p->name << endl; });

  auto mayoresDe20 = filterPersons(personas, [](shared_ptr<Person> p)
                                   { return p->edad > 20; });

  forEachPersons(mayoresDe20, [](shared_ptr<Person> p)
                 { cout << p->name << endl; });

  bool existeAlberto = somePersons(personas, [](shared_ptr<Person> p)
                                   { return p->name == "Alberto"; });
  if (existeAlberto)
    cout << "Hay algun Alberto" << endl;

  bool todosMayoresDe15 = everyPersons(personas, [](shared_ptr<Person> p)
                                       { return p->edad > 15; });

  if (todosMayoresDe15)
    cout << "Todos son mayores de 15" << endl;

  auto todosMasViejos = transformPerson(personas, [](shared_ptr<Person> p)
                                        { 
                                          p->edad++;
                                          return p; });

  for (auto p : todosMasViejos)
    cout << p->name;
}
