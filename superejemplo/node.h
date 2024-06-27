#pragma once

#include "student.h"
#include <memory>
#include <functional>

using namespace std;

struct Node;

using PNode = shared_ptr<Node>;
using LambdaForEach = function<void(Student const &)>;

struct Node
{
  Student data;
  PNode next;
};

/**
 * Adds at the end of the list a student node
 * @return the head of the list
 * @param head The head of the list
 * @param st The student
 */
PNode &push(PNode &head, Student const &st);

/**
 * Iterates over the list (starting at head) and performs f
 */
void forEach(PNode const &head, LambdaForEach const &f);
