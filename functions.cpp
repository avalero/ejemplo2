#include "functions.h"
#include <stdexcept>

int suma(int a, int b)
{
  return a + b;
}

int sumaP(int a, int b)
{
  if (a + b < 0)
    throw std::runtime_error("suma negativa");
  return a + b;
}