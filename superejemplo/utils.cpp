#include "utils.h"

string uuid(int size)
{
  string uuid = "";
  for (int i = 0; i < size; i++)
  {
    uuid += to_string(rand() % 10);
  }
  return uuid;
}

// "(name Alberto)(subjects Progra I, Progra 2, EDA)" ---> {"name Alberto", "subjects Progra I, Progra 2, EDA"}
vector<string> splitInParenthesis(string const &s)
{
  vector<string> result;
  string temp = "";
  for (auto c : s)
  {
    if (c == '(' || c == ')')
    {
      if (temp != "")
      {
        result.push_back(temp);
        temp = "";
      }
    }
    else
    {
      temp += c;
    }
  }
  return result;
}

vector<string> split(string const &s, char delim)
{
  vector<string> result;
  string temp = "";
  for (auto c : s)
  {
    if (c == delim)
    {
      if (temp != "")
      {
        result.push_back(temp);
        temp = "";
      }
    }
    else
    {
      temp += c;
    }
  }
  if (temp != "")
  {
    result.push_back(temp);
  }
  return result;
}

string &trim(string &s)
{
  if (s.empty())
  {
    return s;
  }
  s.erase(0, s.find_first_not_of(" "));
  s.erase(s.find_last_not_of(" ") + 1);
  return s;
}