#include <iostream>
#include <fstream>
#include <string>
#include <array>
using namespace std;

struct Matrix
{
  array<array<float, 3>, 3> data;
};

istream &operator>>(istream &is, Matrix &m)
{
  for (int r{0}; r < m.data.size(); r++)
  {
    for (int c{0}; c < m.data.at(r).size(); c++)
    {
      is >> m.data.at(r).at(c);
    }
  }
  return is;
}

ostream &operator<<(ostream &os, Matrix const &m)
{
  if (typeid(os) == typeid(ofstream))
  {
    for (int r{0}; r < m.data.size(); r++)
    {
      for (int c{0}; c < m.data.at(r).size(); c++)
      {
        os << m.data.at(r).at(c) << " ";
      }
    }
  }
  else
  {
    for (int r{0}; r < m.data.size(); r++)
    {
      for (int c{0}; c < m.data.at(r).size(); c++)
      {
        os << m.data.at(r).at(c) << "\t";
      }
      os << endl;
    }
  }
  return os;
}

int main()
{
  cout << "Introduce los 9 valores de la matriz ordenados por filas y columnas:\n";
  Matrix miMatriz;
  cin >> miMatriz;
  // escribir la matriz en un archivo
  ofstream archivo("data.txt");
  if (!archivo)
  {
    cout << "Error al abrir para escribir\n";
    return -1;
  }

  archivo << miMatriz << endl;

  archivo.close();

  ifstream archivoLectura("data.txt");
  if (!archivoLectura)
  {
    cout << "Error al abrir para leer\n";
    return -1;
  }

  archivoLectura >> miMatriz;

  // leer la matriz de un archivo
  cout << miMatriz;
  return 1;
}