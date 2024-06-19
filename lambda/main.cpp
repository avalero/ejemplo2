#include <functional>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef function<void(int)> flambda;

// for Each --> recorre un vector y hace "algo" con cada uno de sus elementos
void forEach(vi const &v, flambda const &f)
{
  for (auto elem : v)
  {
    f(elem);
  }
}

int main()
{
  flambda print = [](int a)
  { cout << a; };

  vi miVector{1, 2, 3, 4, 5, 6};

  forEach(miVector, print);
  cout << endl;
}
