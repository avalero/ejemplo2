#include <functional>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef function<void(int)> flambda;
typedef function<bool(int)> boollambda;

// for Each --> recorre un vector y hace "algo" con cada uno de sus elementos
void forEach(vi const &v, flambda const &f)
{
  for (auto elem : v)
  {
    f(elem);
  }
}

// some --> recibe un vector y una funcion lambda y devuelva true si algun elemento del vector cumple el requisito de la función
bool some(vi const &v, function<bool(int)> const &f)
{
  for (auto elem : v)
  {
    if (f(elem))
      return true;
  }
  return false;
}

bool every(vi const &v, function<bool(int)> const &f)
{
  for (auto elem : v)
  {
    if (!f(elem))
      return false;
  }

  return true;
}

// v -> {1,2,3,4}, f -> mayor que 2    -----> {3,4}
vector<int> filter(vector<int> const &v, function<bool(int)> const &f)
{
}

// v -> {1,2,3,4}, f --> *2   -----> {2,4,6,8}
vector<int> transform(vector<int> const &v, function<int(int)> const &f)
{
}
int main()
{
  flambda print = [](int a)
  { cout << a; };

  boollambda gt10 = [](int a)
  {
    return a > 10;
  };

  vi miVector{1, 2, 3, 4, 5, 6};

  forEach(miVector, print);
  cout << endl;

  if (some(miVector, gt10))
    cout << "Algun elemento es mayor que 10" << endl;
  else
    cout << "Todos son menores que 10" << endl;

  if (some(miVector, [](int a)
           { return a > 10; }))
  {
    cout << "Alguno es mayor que 10" << endl;
  }

  some(miVector, [](int a)
       { return true; });

  forEach(miVector, [](int elem)
          { cout << 2 * elem; });
}
