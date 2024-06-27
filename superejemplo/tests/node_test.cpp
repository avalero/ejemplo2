#include <gtest/gtest.h>
#include "../node.h"

TEST(Push, push_head_nullptr)
{
  Student st1{"1234", "Alberto", {"Progra I", "Progra 2", "EDA"}};
  // Student st2{"4321", "Luisa", {"Progra I", "Progra 2", "EDA"}};
  PNode head = nullptr;
  head = push(head, st1);
  EXPECT_TRUE(head != nullptr);
  EXPECT_EQ(head->data, st1);
}

TEST(Push, push_head_not_nullptr)
{
  Student st1{"1234", "Alberto", {"Progra I", "Progra 2", "EDA"}};
  Student st2{"4321", "Luisa", {"Progra I", "Progra 2", "EDA"}};
  PNode head = nullptr;
  head = push(head, st1);
  head = push(head, st2);
  EXPECT_TRUE(head != nullptr);
  EXPECT_EQ(head->data, st1);
  EXPECT_EQ(head->next->data, st2);
}