#include <string>
#include <iostream>

using namespace std;

struct Person
{
  string name;
  int age;
};

template <typename T>
void forEach(Vec<T> const &v, lambdavoid<T> const &f)
{
  for (auto elem : v)
    f(elem);
}

template <typename T>
vector<T> filter(vector<T> const &v, function<bool(T)> const &f)
{
  vector<T> result;
  for (auto elem : v)
    if (f(elem))
      result.push_back(elem);
  return result;
}