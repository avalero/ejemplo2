#include <iostream>
#include <cmath>

using namespace std;

class Complejo
{
  friend Complejo operator+(Complejo const &c1, Complejo const &c2);
  friend ostream &operator<<(ostream &os, Complejo const &c);

public:
  Complejo(float real, float im) : real{real}, im{im}
  {
  }

  float getImaginario() const
  {
    return im;
  }

  float getReal() const
  {
    return real;
  }

  void setImaginario(float imaginario)
  {
    im = imaginario;
  }

  void setReal(float r)
  {
    real = r;
  }

  float getModule() const
  {
    return sqrt(real * real + im * im);
  }

private:
  float real;
  float im;
};

Complejo suma(Complejo const &c1, Complejo const &c2)
{
  return Complejo{c1.getReal() + c2.getReal(), c1.getImaginario() + c2.getImaginario()};
}

Complejo operator+(Complejo const &c1, Complejo const &c2)
{
  return Complejo{c1.real + c2.real, c1.im + c2.im};
}

ostream &operator<<(ostream &os, Complejo const &c)
{
  os << c.real << " + " << c.im << "i";
  return os;
}
int main()
{
  Complejo c1{1, 1};
  Complejo c2{3, 2};

  auto c3 = c1 + c2;
}