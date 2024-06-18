#include <gtest/gtest.h>
#include <memory>
#include <vector>
#include "../types.h"
#include "../functions.h"

using namespace std;

TEST(functions_test, includes_test)
{
  vector<shared_ptr<Person>> personas;

  shared_ptr<Person> unaPersona = make_shared<Person>(Person{"Luis", 33, true});
  shared_ptr<Person> otraPersona = make_shared<Person>(Person{"Luis", 33, true});
  personas.push_back(unaPersona);

  personas.push_back(make_shared<Person>(Person{"Alberto", 21, true}));
  personas.push_back(make_shared<Person>(Person{"Alberto2", 16, true}));
  personas.push_back(make_shared<Person>(Person{"Alberto3", 20, true}));
  personas.push_back(make_shared<Person>(Person{"Alberto4", 15, true}));
  personas.push_back(make_shared<Person>(Person{"Alberto5", 14, true}));
  personas.push_back(make_shared<Person>(Person{"Alberto6", 84, true}));

  EXPECT_TRUE(includes(personas, unaPersona));
  EXPECT_FALSE(includes(personas, otraPersona));
}

TEST(functions_test, includes_vectors_test)
{
  shared_ptr<Person> persona1 = make_shared<Person>(Person{"Luis", 33, true});
  shared_ptr<Person> persona2 = make_shared<Person>(Person{"Andres", 33, true});
  shared_ptr<Person> persona3 = make_shared<Person>(Person{"Alberto", 21, true});
  shared_ptr<Person> persona4 = make_shared<Person>(Person{"Alberto2", 16, true});
  shared_ptr<Person> persona5 = make_shared<Person>(Person{"Alberto3", 20, true});
  shared_ptr<Person> persona6 = make_shared<Person>(Person{"Alberto4", 15, true});
  shared_ptr<Person> persona7 = make_shared<Person>(Person{"Alberto5", 14, true});

  vector<shared_ptr<Person>> personas{persona1, persona2, persona3, persona5, persona6, persona7};
  vector<shared_ptr<Person>> subvector{persona3, persona5, persona6, persona7};

  EXPECT_TRUE(includes(personas, subvector));
}

TEST(functions_test, intersection_test)
{

  shared_ptr<Person> persona1 = make_shared<Person>(Person{"Luis", 33, true});
  shared_ptr<Person> persona2 = make_shared<Person>(Person{"Andres", 33, true});
  shared_ptr<Person> persona3 = make_shared<Person>(Person{"Alberto", 21, true});
  shared_ptr<Person> persona4 = make_shared<Person>(Person{"Alberto2", 16, true});
  shared_ptr<Person> persona5 = make_shared<Person>(Person{"Alberto3", 20, true});
  shared_ptr<Person> persona6 = make_shared<Person>(Person{"Alberto4", 15, true});
  shared_ptr<Person> persona7 = make_shared<Person>(Person{"Alberto5", 14, true});

  vector<shared_ptr<Person>> personas1{persona1, persona2, persona3, persona5, persona6, persona7};
  vector<shared_ptr<Person>> personas2{persona3, persona4, persona5, persona6, persona7};

  auto result = intersection(personas1, personas2);

  EXPECT_EQ(result.size(), 4);
  EXPECT_TRUE(includes(result, {persona3, persona5, persona6, persona7}));
}

TEST(functions_test, vector_union_test)
{
  shared_ptr<Person> persona1 = make_shared<Person>(Person{"Luis", 33, true});
  shared_ptr<Person> persona2 = make_shared<Person>(Person{"Andres", 33, true});
  shared_ptr<Person> persona3 = make_shared<Person>(Person{"Alberto", 21, true});
  shared_ptr<Person> persona4 = make_shared<Person>(Person{"Alberto2", 16, true});
  shared_ptr<Person> persona5 = make_shared<Person>(Person{"Alberto3", 20, true});
  shared_ptr<Person> persona6 = make_shared<Person>(Person{"Alberto4", 15, true});
  shared_ptr<Person> persona7 = make_shared<Person>(Person{"Alberto5", 14, true});

  vector<shared_ptr<Person>> personas1{persona1, persona2, persona3, persona5, persona6, persona7};
  vector<shared_ptr<Person>> personas2{persona3, persona4, persona5, persona6, persona7};

  auto result = vectorUnion(personas1, personas2);

  EXPECT_EQ(result.size(), 7);
  EXPECT_TRUE(includes(result, persona1));
  EXPECT_TRUE(includes(result, persona2));
  EXPECT_TRUE(includes(result, persona3));
  EXPECT_TRUE(includes(result, persona4));
  EXPECT_TRUE(includes(result, persona5));
  EXPECT_TRUE(includes(result, persona6));
  EXPECT_TRUE(includes(result, persona7));
}

TEST(functions_test, difference_test)
{
  shared_ptr<Person> persona1 = make_shared<Person>(Person{"Luis", 33, true});
  shared_ptr<Person> persona2 = make_shared<Person>(Person{"Andres", 33, true});
  shared_ptr<Person> persona3 = make_shared<Person>(Person{"Alberto", 21, true});
  shared_ptr<Person> persona4 = make_shared<Person>(Person{"Alberto2", 16, true});
  shared_ptr<Person> persona5 = make_shared<Person>(Person{"Alberto3", 20, true});
  shared_ptr<Person> persona6 = make_shared<Person>(Person{"Alberto4", 15, true});
  shared_ptr<Person> persona7 = make_shared<Person>(Person{"Alberto5", 14, true});

  vector<shared_ptr<Person>> personas1{persona1, persona2, persona3, persona5, persona6, persona7};
  vector<shared_ptr<Person>> personas2{persona3, persona4, persona5, persona6, persona7};

  auto result = difference(personas1, personas2);

  EXPECT_EQ(result.size(), 2);
  EXPECT_TRUE(includes(result, persona1));
  EXPECT_TRUE(includes(result, persona2));
}