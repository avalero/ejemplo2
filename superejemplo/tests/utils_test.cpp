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