#include <memory>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

struct Coordinates
{
  int x;
  int y;
};

struct Node;

struct Edge
{
  shared_ptr<Node> node;
  float distance;
};

bool operator<(Edge const &e1, Edge const &e2) { return e1.distance < e2.distance; }

struct Node
{
  Coordinates data;
  set<Edge> neighbors;
  float cost = INT_MAX;
  shared_ptr<Node> prev;
};

float operator-(Coordinates const &c1, Coordinates const &c2)
{
  return (c2.x - c1.x) * (c2.x - c1.x) + (c2.y - c1.y) * (c2.y - c1.y);
}

void push(shared_ptr<Node> &n1, shared_ptr<Node> &n2, bool bidirectional = true)
{
  auto edge = Edge{n2, n2->data - n1->data};
  n1->neighbors.insert(edge);

  if (bidirectional)
  {
    auto edge = Edge(n1, n1->data - n2->data);
    n2->neighbors.insert(edge);
  }
}

void dijkstra(shared_ptr<Node> start, vector<shared_ptr<Node>> nodes)
{
  start->cost = 0;
  auto NOT_VISITED = nodes;

  while (NOT_VISITED.size() > 0)
  {
    auto current = NOT_VISITED.at(0);
    for (auto node : NOT_VISITED)
    {
      if (node->cost < current->cost)
        current = node;
    }

    // remove current from NOT_VISITED
    NOT_VISITED.erase(find(NOT_VISITED.begin(), NOT_VISITED.end(), current));

    for (auto edge : current->neighbors)
    {
      if (edge.node->cost > current->cost + edge.distance)
      {
        edge.node->cost = current->cost + edge.distance;
        edge.node->prev = current;
      }
    }
  }
}

int main()
{
  return 0;
}