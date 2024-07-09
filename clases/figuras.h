#pragma once

class FiguraGeometricaReg
{
public:
  FiguraGeometricaReg(int nlados, float lado);

  void setnlados(int n);
  void setLado(float l);

  int getnlados() const;
  float getLado() const;
  float getPerimetro() const;

  virtual float getArea() const { return 0; };
  virtual void queSoy() const;

protected:
  int nlados;
  float lado;
};

class Cuadrado : public FiguraGeometricaReg
{
public:
  Cuadrado(float lado);
  float getDiagonal() const;
  float getArea() const;
  void queSoy() const;
};

class TrianguloEq : public FiguraGeometricaReg
{
public:
  TrianguloEq(float lado);
  float getArea() const;
  float getAltura() const;
  void queSoy() const;
};