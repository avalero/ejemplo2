#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Student
{
  string id;
  string name;
  vector<string> subjects;
};

bool operator==(Student const &st1, Student const &st2);
ostream &operator<<(ostream &os, Student const &s);

// // id name subject1 subject2 subject3 ...
// istream &operator>>(istream &is, Student &s)
// {
//   is >> s.id;
//   is >> s.name;
//   string aux;
//   while (is >> aux)
//   {
//     s.subjects.push_back(aux);
//   }
//   return is;
// }