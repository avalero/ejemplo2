#include <iostream>
#include <fstream>
#include <string>
#include <array>
using namespace std;

struct Person
{
  string name;
  int edad;
};

ostream &operator<<(ostream &os, Person const &p)
{
  os << p.name << " " << p.edad;
  return os;
}

istream &operator>>(istream &is, Person &p)
{
  is >> p.name >> p.edad;
  return is;
}

int main()
{
  // cout << "Introduce nombre y edad separado por espacio: \n";
  // Person p;
  // cin >> p;

  // ofstream archivo("data.txt");
  // if (!archivo)
  // {
  //   cout << "Error\n";
  //   return -1;
  // }

  // archivo << p << endl;

  // archivo.close();

  ifstream archivoIn("data.txt");
  if (!archivoIn)
  {
    return -1;
  }

  Person p;
  while (archivoIn >> p)
  {
    cout << p << endl;
  }
}