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