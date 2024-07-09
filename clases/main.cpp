#include "figuras.h"
#include <vector>
#include <memory>
#include <iostream>

using namespace std;

int main()
{
  shared_ptr<Cuadrado> c = make_shared<Cuadrado>(Cuadrado{5});
  shared_ptr<TrianguloEq> t = make_shared<TrianguloEq>(TrianguloEq{5});

  std::vector<shared_ptr<FiguraGeometricaReg>> fig;
  fig.push_back(c);
  fig.push_back(t);
  fig.at(0)->queSoy();
  fig.at(1)->queSoy();

  cout << dynamic_cast<Cuadrado *>(fig.at(0).get())->getDiagonal() << endl;
  cout << dynamic_cast<TrianguloEq *>(fig.at(1).get())->getAltura() << endl;

  shared_ptr<Cuadrado> c2 = make_shared<Cuadrado>(dynamic_cast<Cuadrado *>(fig.at(1).get()));

  if (!c2)
  {
    cout << "No se pudo hacer el cast" << endl;
  }
  else
  {
    cout << "Se pudo hacer el cast" << endl;
  }

  return 0;
}