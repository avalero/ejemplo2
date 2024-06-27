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

/**
 * Filters the list (starting at head) and returns a new list with the elements that satisfy f
 * @return the new list (vector of shared_ptr<Node>)
 * @param head The head of the list
 * @param f The filter function
 * @example
 * auto f = [](Student const &st) { return st.name == "Alberto"; };
 * auto new_list = filter(head, f);
 * forEach(new_list, [](Student const &st) { cout << st << endl; });
 */
vector<PNode> filter(PNode const &head, function<bool(Student const &)> const &f);

/**
 * Finds the first element that satisfies f
 * @return the element that satisfies f
 * @param head The head of the list
 * @param f The filter function
 * @example
 * auto f = [](Student const &st) { return st.name == "Alberto"; };
 * auto node = find(head, f);
 * cout << node->data << endl;
 */
PNode find(PNode const &head, function<bool(Student const &)> const &f);

/**
 * Finds the last element that satisfies f
 * @return the element that satisfies f
 * @param head The head of the list
 * @param f The filter function
 * @example
 * auto f = [](Student const &st) { return st.name == "Alberto"; };
 * auto node = findLast(head, f);
 * cout << node->data << endl;
 *
 */
PNode findLast(PNode const &head, function<bool(Student const &)> const &f);