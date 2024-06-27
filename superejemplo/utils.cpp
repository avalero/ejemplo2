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