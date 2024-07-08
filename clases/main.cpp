#include <iostream>

using namespace std;

class Person
{

public:
  Person(string n, int e)
  {
    cout << "Constructor con parametros" << endl;
    if (e < 0)
    {
      cout << "La edad no puede ser menor que 0" << endl;
      throw new string("Errro de edad");
    }

    edad = e;
    name = n;
  }

  Person()
  {
    cout << "constructor sin parámetros" << endl;
    edad = 0;
    name = "";
  }

private:
  string name;
  int edad;

public:
  string getName() { return name; }
  void setName(string const &n) { name = n; }

  int getEdad() { return edad; }
  void setEdad(int e)
  {
    if (e < 0)
      throw new string{"La edad no puede ser menor que 0"};
    edad = e;
  }
  void cumplirAños()
  {
    edad++;
  }
  void print()
  {
    cout << "Nombre: " << name << endl;
    cout << "Edad: " << edad << endl;
  }
};

int main()
{
  // Person unaPersona{"Alberto", 16};
  Person otraPersona{"Alberto", -34};
  otraPersona.setEdad(-23);

  // unaPersona.print();

  return 1;
}
