#include "student.h"
#include "utils.h"
#include <fstream>

using namespace std;

string serializeStudent(Student const &s)
{
  string result = "(name " + s.name + ")(subjects ";
  for (auto subject : s.subjects)
  {
    result += subject + ",";
  }
  // remove last comma
  result.pop_back();
  result += ")";
  return result;
}

ostream &operator<<(ostream &os, Student const &s)
{
  if (typeid(os) == typeid(ofstream))
  {
    os << serializeStudent(s);
    return os;
  }
  else
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
}

bool operator==(Student const &st1, Student const &st2)
{
  return st1.id == st2.id;
}

// "(name Alberto Valero)(subjects Progra I Progra 2 EDA)"
istream &operator>>(istream &is, Student &s)
{
  // read full istream
  string line;
  getline(is, line);

  auto parts = splitInParenthesis(line); // {"name Alberto Valero", "subjects Progra I Progra 2 EDA"}

  for (auto part : parts)
  {
    if (part.starts_with("name"))
    {
      s.name = parseName(part);
    }
    else if (part.starts_with("subjects"))
    {
      s.subjects = parseSubjects(part);
    }
  }

  s.id = uuid(6);

  return is;
}

// "name Alberto Valero" --> "Alberto Valero"
string parseName(string const &n)
{
  if (!n.starts_with("name"))
  {
    return "";
  }
  auto tokens = split(n, ' '); // {"name", "Alberto", "Valero"}
  string name = "";
  for (int i{1}; i < tokens.size(); i++)
  {
    name += tokens.at(i);
    name += " ";
  }
  name = trim(name);
  return name;
}

vector<string> parseSubjects(string const &part)
{
  vector<string> result;
  if (!part.starts_with("subjects"))
    return result;
  // "subjects Progra I, Progra II, EDA"
  // remove starting sujects from string
  if (part.length() < 9)
    return result;                    // "subjects" (8 chars) + " " (1 char
  auto sbjstr = part.substr(9);       // Progra I, Progra II, EDA;
  auto subjects = split(sbjstr, ','); // {"Progra I", "Progra II", "EDA"}
  for (auto subject : subjects)
  {
    result.push_back(trim(subject));
  }
  return result;
}
