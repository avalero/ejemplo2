#include <iostream>

using namespace std;

struct Person
{
  string name;
  int age;
};

template <typename T>
T suma(T a, T b)
{
  return a + b;
}

Person suma(Person a, Person b)
{
  return a;
}

int main()
{
  auto c = suma<int>(3, 4);
  auto b = suma<string>("hola", "adios");
  auto h = suma<Person>(Person{"Alberto", 18}, Person{"Maria", 24});

  return 0;
}