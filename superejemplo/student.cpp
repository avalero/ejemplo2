#include "student.h"

ostream &operator<<(ostream &os, Student const &s)
{
  os << "id: " << s.id << endl;
  os << "Name: " << s.name << endl;
  os << "Subects:\n=============\n";
  for (auto subject : s.subjects)
  {
    os << "  - " << subject << endl;
  }
  return os;
}

bool operator==(Student const &st1, Student const &st2)
{
  return st1.id == st2.id;
}
