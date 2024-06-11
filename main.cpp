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
  vector<Person> personas{alberto, maria};
  personas.push_back(alberto);
  personas.push_back(maria);

  personas.at(0); // alberto
  personas.at(1); // maria
  personas.at(2); // alberto
  personas.at(3); // maria

  cout << personas.size() << endl; // 4

  return 0;
}

// Luis
// 18
// Hyiundai
// Luis
// 18
// Hyundai
// Luis