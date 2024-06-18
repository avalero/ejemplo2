#pragma once

#include <memory>
#include <vector>
#include "types.h"

using namespace std;

bool includes(vector<shared_ptr<Person>> const &v, shared_ptr<Person> const &person);
bool includes(vector<shared_ptr<Person>> const &v, vector<shared_ptr<Person>> const &subvector);