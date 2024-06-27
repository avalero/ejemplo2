#include <gtest/gtest.h>
#include "../student.h"
#include <fstream>

TEST(ParseName, parse_name)
{
  string s = "name Alberto";
  auto result = parseName(s);
  EXPECT_EQ(result, "Alberto");
}

TEST(ParseName, parse_name_empty)
{
  string s = "name";
  auto result = parseName(s);
  EXPECT_EQ(result, "");
}

TEST(ParseName, parse_name_no_name)
{
  string s = "Alberto";
  auto result = parseName(s);
  EXPECT_EQ(result, "");
}

TEST(ParseName, parse_long_name)
{
  string s = "name Alberto Valero";
  auto result = parseName(s);
  EXPECT_EQ(result, "Alberto Valero");
}

TEST(parseSubjects, parse_subjects)
{
  string s = "subjects Progra I, Progra 2, EDA";
  auto result = parseSubjects(s);
  vector<string> expected{"Progra I", "Progra 2", "EDA"};
  EXPECT_EQ(result, expected);
}

TEST(parseSubjects, parse_subjects_empty)
{
  string s = "subjects";
  auto result = parseSubjects(s);
  vector<string> expected{};
  EXPECT_EQ(result, expected);
}

TEST(createStudent, createStudentFromIStream)
{
  string s = "(name Alberto Valero)(subjects Progra I, Progra 2, EDA)";
  istringstream is{s};
  Student st;
  is >> st;
  EXPECT_EQ(st.name, "Alberto Valero");
  EXPECT_EQ(st.subjects.size(), 3);
  EXPECT_EQ(st.subjects[0], "Progra I");
  EXPECT_EQ(st.subjects[1], "Progra 2");
  EXPECT_EQ(st.subjects[2], "EDA");
}

TEST(serializeStudent, serializeStudentToOStream)
{
  Student st{"1234", "Alberto Valero", {"Progra I", "Progra 2", "EDA"}};
  string result = serializeStudent(st);
  string expected = "(name Alberto Valero)(subjects Progra I,Progra 2,EDA)";
  EXPECT_EQ(result, expected);
}

TEST(WriteToFile, writeToFile)
{
  string filename = "students1.txt";
  vector<Student> students{
      {"1234", "Alberto Valero", {"Progra I", "Progra 2", "EDA"}},
      {"4321", "Luisa", {"Progra I"}}};

  std::ofstream os{filename};
  for (auto st : students)
  {
    os << st << endl;
  }

  os.close();

  ifstream is{filename};

  vector<string> lines;
  string line;
  while (getline(is, line))
  {
    lines.push_back(line);
  }

  EXPECT_EQ(lines.size(), 2);
  EXPECT_EQ(lines[0], "(name Alberto Valero)(subjects Progra I,Progra 2,EDA)");
  EXPECT_EQ(lines[1], "(name Luisa)(subjects Progra I)");

  is.close();
}

TEST(ReadFromFile, writeToFile)
{
  string filename = "students2.txt";
  vector<Student> students{
      {"1234", "Alberto Valero", {"Progra I", "Progra 2", "EDA"}},
      {"4321", "Luisa", {"Progra I"}}};

  std::ofstream os{filename};
  for (auto st : students)
  {
    os << st << endl;
  }

  os.close();

  ifstream is{filename};

  vector<Student> students_read;
  Student st;
  while (is >> st)
  {
    students_read.push_back(st);
  }

  is.close();

  EXPECT_EQ(students_read.size(), 2);
  EXPECT_EQ(students_read[0].name, "Alberto Valero");
  EXPECT_EQ(students_read[0].subjects.size(), 3);
  EXPECT_EQ(students_read[0].subjects[0], "Progra I");
  EXPECT_EQ(students_read[0].subjects[1], "Progra 2");
  EXPECT_EQ(students_read[0].subjects[2], "EDA");

  EXPECT_EQ(students_read[1].name, "Luisa");
  EXPECT_EQ(students_read[1].subjects.size(), 1);
  EXPECT_EQ(students_read[1].subjects[0], "Progra I");
}