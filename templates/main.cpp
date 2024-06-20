#include <iostream>
#include <vector>
#include <functional>

using namespace std;

struct Person
{
  string name;
  int age;
};

template <typename T>
void forEach(vector<T> const &v, function<void(T)> const &f)
{
  for (auto elem : v)
    f(elem);
}

int main()
{

  vector<int> v{1, 2, 3, 34, 4, 5, 5, 6, 3};
  forEach<int>(v, [](int elem)
               { cout << elem; });

  forEach<Person>({Person("Alberto", 12), Person("Lucia", 13)}, [](Person l)
                  { cout << l.name; });

  return 0;
}