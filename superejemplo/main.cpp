#include "student.h"
#include "node.h"

int main()
{
  Student st1{"1234", "Alberto", {"Progra I", "Progra 2", "EDA"}};
  Student st2{"4321", "Luisa", {"Progra I", "Progra 2", "EDA"}};
  PNode head = nullptr;
  push(head, st1);
  push(head, st2);

  forEach(head, [](Student const &st)
          { cout << st << endl; });

  return 1;
}