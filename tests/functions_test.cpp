#include <gtest/gtest.h>
#include "../functions.h"

TEST(SumaTest, suma_correctamente)
{
  EXPECT_EQ(suma(3, 4), 7);
}

// compruebo el caso correcto
TEST(SumaPTest, sumaP_correctamente)
{
  EXPECT_EQ(sumaP(3, 4), 7);
}

// compruebo que si suma negativo lanza excepcion
TEST(SumaPTest, sumaP_lanzaerror)
{
  // expect exception
  EXPECT_ANY_THROW(sumaP(3, -4));
}

// compruebo que si no es negativo NO lanza excepcion
TEST(SumaPTest, sumaP_no_lanzaerror)
{
  // expect exception
  EXPECT_NO_THROW(sumaP(3, 4));
}