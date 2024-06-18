#include "functions.h"

bool includes(vector<shared_ptr<Person>> const &v, shared_ptr<Person> const &person)
{
  for (auto const &p : v)
  {
    if (person == p)
      return true;
  }
  return false;
}