#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Car
{
  string brand;
  string plate;
};

struct Person
{
  string name;
  int age;
  string dni;
  string email;
  Car car;
};

void printPerson(Person const &p)
{
  cout << "Nombre: " << p.name << "\n";
  cout << "Edad: " << p.age << endl;
  cout << "Marca del coche: " << p.car.brand << endl;
}

int main()
{
  Person alberto{"Alberto", 18, "123456789J", "alberto.valero@bq.com", Car{"Hyundai", "1234ABC"}};
  Person maria{"Maria", 20, "123436789J", "maria@bq.com", Car{"Kia", "1234ABC"}};
  Person luis{"Luis", 14, "123436789J", "maria@bq.com", Car{"Kia", "1234ABC"}};
  vector<Person> personas{alberto, maria, luis};

  for (int i{0}; i < personas.size(); i++)
  {
    if (personas.at(i).age >= 18)
      cout << personas.at(i).name << endl;
  }

  for (Person p : personas)
  {
    if (p.age >= 18)
      cout << p.name << endl;
  }

  return 0;
}

// Luis
// 18
// Hyiundai
// Luis
// 18
// Hyundai
// Luis