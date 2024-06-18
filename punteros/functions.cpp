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

bool includes(vector<shared_ptr<Person>> const &v, vector<shared_ptr<Person>> const &subvector)
{
  for (auto const &p : subvector)
  {
    if (!includes(v, p))
      return false;
  }
  return true;
}

vector<shared_ptr<Person>> intersection(vector<shared_ptr<Person>> const &v1, vector<shared_ptr<Person>> const &v2)
{
  vector<shared_ptr<Person>> result;
  for (auto const &p : v1)
  {
    if (includes(v2, p))
      result.push_back(p);
  }
  return result;
}
vector<shared_ptr<Person>> vectorUnion(vector<shared_ptr<Person>> const &v1, vector<shared_ptr<Person>> const &v2)
{
  vector<shared_ptr<Person>> result;
  for (auto const &p : v1)
  {
    result.push_back(p);
  }
  for (auto const &p : v2)
  {
    if (!includes(result, p))
      result.push_back(p);
  }
  return result;
}

vector<shared_ptr<Person>> difference(vector<shared_ptr<Person>> const &v1, vector<shared_ptr<Person>> const &v2)
{
  vector<shared_ptr<Person>> result;
  for (auto const &p : v1)
  {
    if (!includes(v2, p))
      result.push_back(p);
  }
  return result;
}