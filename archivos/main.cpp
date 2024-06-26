#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Point
{
  float x;
  float y;
};

Point operator+(Point const &a, Point const &b)
{
  return Point({a.x + b.x, a.y + b.y});
}

ostream &operator<<(ostream &os, Point const &p)
{
  os << "(" << p.x << " , " << p.y << ")";
  return os;
}

istream &operator>>(istream &is, Point &p)
{
  int x, y;
  is >> p.x >> p.y;
  return is;
}

int main()
{
  Point a{3, 2};
  cout << "El punto a es: " << a << endl;
  cout << "Escribe un punto: ";
  cin >> a;
  cout << a << endl;

  // open file and rewrite
  // ofstream miArchivo("archivo.txt", ios::app);

  // if (!miArchivo)
  // {
  //   cout << "No se ha creado el archivo" << endl;
  //   return -1;
  // }

  // miArchivo << "Estoy guardando en el archivo" << endl;
  // miArchivo << "El punto es " << a << endl;

  ifstream archivoParaLeer("archivo.txt");
  if (!archivoParaLeer)
  {
    cout << "No se ha podido abrir el archivo" << endl;
    return -1;
  }

  string line;
  while (getline(archivoParaLeer, line))
  {
    cout << line << endl;
  }

  archivoParaLeer.close();

  // miArchivo.close();
}