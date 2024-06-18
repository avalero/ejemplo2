#pragma once

#include <memory>
#include <vector>
#include "types.h"

using namespace std;

bool includes(vector<shared_ptr<Person>> const &v, shared_ptr<Person> const &person);
bool includes(vector<shared_ptr<Person>> const &v, vector<shared_ptr<Person>> const &subvector);
vector<shared_ptr<Person>> intersection(vector<shared_ptr<Person>> const &v1, vector<shared_ptr<Person>> const &v2);
vector<shared_ptr<Person>> vectorUnion(vector<shared_ptr<Person>> const &v1, vector<shared_ptr<Person>> const &v2);
vector<shared_ptr<Person>> difference(vector<shared_ptr<Person>> const &v1, vector<shared_ptr<Person>> const &v2);