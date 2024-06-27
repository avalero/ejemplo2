#include <gtest/gtest.h>
#include "../utils.h"

TEST(uuid, uuid_size)
{
  int size = 10;
  string id = "";
  id = uuid(size);
  EXPECT_EQ(id.size(), size);
}

TEST(uuid, uuid_not_empty)
{
  int size = 10;
  string id = "";
  id = uuid(size);
  EXPECT_TRUE(id != "");
}

TEST(uuid, uuid_not_equal)
{
  int size = 10;
  string uuid1 = "";
  string uuid2 = "";
  uuid1 = uuid(size);
  uuid2 = uuid(size);
  EXPECT_TRUE(uuid1 != uuid2);
}

TEST(splitInParenthesis, splitInParenthesis_empty)
{
  string s = "";
  auto result = splitInParenthesis(s);
  EXPECT_EQ(result.size(), 0);
}

TEST(splitInParenthesis, splitInParenthesis_one)
{
  string s = "(name Alberto)";
  auto result = splitInParenthesis(s);
  EXPECT_EQ(result.size(), 1);
  EXPECT_EQ(result[0], "name Alberto");
}

TEST(splitInParenthesis, splitInParenthesis_two)
{
  string s = "(name Alberto)(subjects Progra I, Progra 2, EDA)";
  auto result = splitInParenthesis(s);
  EXPECT_EQ(result.size(), 2);
  EXPECT_EQ(result[0], "name Alberto");
  EXPECT_EQ(result[1], "subjects Progra I, Progra 2, EDA");
}

TEST(split, split_empty)
{
  string s = "";
  char delim = ',';
  auto result = split(s, delim);
  EXPECT_EQ(result.size(), 0);
}

TEST(split, split_one)
{
  string s = "Progra I";
  char delim = ',';
  auto result = split(s, delim);
  EXPECT_EQ(result.size(), 1);
  EXPECT_EQ(result[0], "Progra I");
}

TEST(split, split_two)
{
  string s = "Progra I, Progra 2, EDA";
  char delim = ',';
  auto result = split(s, delim);
  EXPECT_EQ(result.size(), 3);
  EXPECT_EQ(result[0], "Progra I");
  EXPECT_EQ(result[1], " Progra 2");
  EXPECT_EQ(result[2], " EDA");
}

TEST(trim, trim_empty)
{
  string s = "";
  trim(s);
  EXPECT_EQ(s, "");
}

TEST(trim, trim_no_spaces)
{
  string s = "Progra I";
  trim(s);
  EXPECT_EQ(s, "Progra I");
}

TEST(trim, trim_spaces)
{
  string s = " Progra I ";
  trim(s);
  EXPECT_EQ(s, "Progra I");
}