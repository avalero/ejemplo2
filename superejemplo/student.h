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

istream &operator>>(istream &is, Student &s);

string parseName(string const &n);
vector<string> parseSubjects(string const &part);

string serializeStudent(Student const &s);