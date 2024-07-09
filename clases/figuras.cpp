#include "figuras.h"
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

FiguraGeometricaReg::FiguraGeometricaReg(int nlados, float lado) : nlados{nlados}, lado{lado}
{
  if (nlados < 3 || lado <= 0)
  {
    throw new string{"Invalid dimensions"};
  }
}

int FiguraGeometricaReg::getnlados() const { return nlados; }
float FiguraGeometricaReg::getLado() const { return lado; }

void FiguraGeometricaReg::setnlados(int n)
{
  if (n < 3)
  {
    throw new string{"Invalid number of sides"};
  }
  nlados = n;
}

void FiguraGeometricaReg::setLado(float l)
{
  if (l <= 0)
  {
    throw new string{"Invalid side length"};
  }
  lado = l;
}

float FiguraGeometricaReg::getPerimetro() const
{
  return nlados * lado;
}

Cuadrado::Cuadrado(float lado) : FiguraGeometricaReg(4, lado) {}

float Cuadrado::getDiagonal() const
{
  return lado * sqrt(2);
}

float Cuadrado::getArea() const
{
  return lado * lado;
}

TrianguloEq::TrianguloEq(float lado) : FiguraGeometricaReg(3, lado) {}

float TrianguloEq::getArea() const
{
  return sqrt(3) / 4 * lado * lado;
}

float TrianguloEq::getAltura() const
{
  return sqrt(3) / 2 * lado;
}

void FiguraGeometricaReg::queSoy() const
{
  cout << "Soy una figura geometrica regular\n";
}

void Cuadrado::queSoy() const
{
  cout << "Soy un cuadrado\n";
}

void TrianguloEq::queSoy() const
{
  cout << "Soy un triangulo equilatero\n";
}