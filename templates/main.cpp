#include <iostream>
#include <vector>
#include <functional>
#include <memory>

using namespace std;

template <typename T>
using Vec = std::vector<T>;

template <typename T>
using lambdavoid = function<void(T)>;

int main()
{
  vector<int> v{1, 2, 3, 34, 4, 5, 5, 6, 3};
  forEach<int>(v, [](int elem)
               { cout << elem; });

  forEach<Person>({Person("Alberto", 12), Person("Lucia", 13)}, [](Person l)
                  { cout << l.name; });

  vector<shared_ptr<Person>> vector = {
      make_shared<Person>(Person{"Alberto", 12}),
      make_shared<Person>(Person{"Luisa", 12})};

  auto resultado = filter<shared_ptr<Person>>(vector, [](shared_ptr<Person> p)
                                              { return true; });

  return 0;
}