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

TEST(filter, filter_empty_list)
{
  PNode head = nullptr;
  auto f = [](Student const &st)
  { return st.name == "Alberto"; };
  auto new_list = filter(head, f);
  EXPECT_EQ(new_list.size(), 0);
}

TEST(filter, filter_not_empty_list)
{
  Student st1{"1234", "Alberto", {"Progra I", "Progra 2", "EDA"}};
  Student st2{"4321", "Luisa", {"Progra I", "Progra 2", "EDA"}};
  PNode head = nullptr;
  head = push(head, st1);
  head = push(head, st2);
  auto f = [](Student const &st)
  { return st.name == "Alberto"; };
  auto new_list = filter(head, f);
  EXPECT_EQ(new_list.size(), 1);
  EXPECT_EQ(new_list[0]->data, st1);
}

TEST(filter, filter_not_matching)
{
  Student st1{"1234", "Alberto", {"Progra I", "Progra 2", "EDA"}};
  Student st2{"4321", "Luisa", {"Progra I", "Progra 2", "EDA"}};
  PNode head = nullptr;
  head = push(head, st1);
  head = push(head, st2);
  auto f = [](Student const &st)
  { return st.name == "Andres"; };
  auto new_list = filter(head, f);
  EXPECT_EQ(new_list.size(), 0);
}

TEST(filter, filter_several_matching)
{
  Student st1{"1234", "Alberto", {"Progra I", "Progra 2", "EDA"}};
  Student st2{"4321", "Luisa", {"Progra I", "Progra 2", "EDA"}};
  Student st3{"5678", "Alberto", {"Progra I", "Progra 2", "EDA"}};
  PNode head = nullptr;
  head = push(head, st1);
  head = push(head, st2);
  head = push(head, st3);
  auto f = [](Student const &st)
  { return st.name == "Alberto"; };
  auto new_list = filter(head, f);
  EXPECT_EQ(new_list.size(), 2);
  EXPECT_EQ(new_list[0]->data, st1);
  EXPECT_EQ(new_list[1]->data, st3);
}

TEST(find, filter_not_matching)
{
  Student st1{"1234", "Alberto", {"Progra I", "Progra 2", "EDA"}};
  Student st2{"4321", "Luisa", {"Progra I", "Progra 2", "EDA"}};
  PNode head = nullptr;
  head = push(head, st1);
  head = push(head, st2);
  auto f = [](Student const &st)
  { return st.name == "Andres"; };
  auto found = find(head, f);
  EXPECT_EQ(found, nullptr);
}

TEST(find, filter_matching)
{
  Student st1{"1234", "Alberto", {"Progra I", "Progra 2", "EDA"}};
  Student st2{"4321", "Luisa", {"Progra I", "Progra 2", "EDA"}};
  PNode head = nullptr;
  head = push(head, st1);
  head = push(head, st2);

  auto f = [](Student const &st)
  { return st.name == "Alberto"; };
  auto found = find(head, f);
  EXPECT_TRUE(found != nullptr);
  EXPECT_EQ(found->data, st1);
}

TEST(findLast, filter_not_matching)
{
  Student st1{"1234", "Alberto", {"Progra I", "Progra 2", "EDA"}};
  Student st2{"4321", "Luisa", {"Progra I", "Progra 2", "EDA"}};
  PNode head = nullptr;
  head = push(head, st1);
  head = push(head, st2);
  auto f = [](Student const &st)
  { return st.name == "Andres"; };
  auto found = findLast(head, f);
  EXPECT_EQ(found, nullptr);
}

TEST(findLast, filter_matching)
{
  Student st1{"1234", "Alberto", {"Progra I", "Progra 2", "EDA"}};
  Student st2{"4321", "Luisa", {"Progra I", "Progra 2", "EDA"}};
  Student st3{"5678", "Alberto", {"Progra I", "Progra 2", "EDA"}};
  PNode head = nullptr;
  head = push(head, st1);
  head = push(head, st2);
  head = push(head, st3);

  auto f = [](Student const &st)
  { return st.name == "Alberto"; };
  auto found = findLast(head, f);
  EXPECT_TRUE(found != nullptr);
  EXPECT_EQ(found->data, st3);
}