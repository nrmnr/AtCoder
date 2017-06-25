#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Town
{
  int id, x, y;
};

bool comp_x(const Town& t1, const Town& t2)
{
  return t1.x < t2.x;
};

bool comp_y(const Town& t1, const Town& t2)
{
  return t1.y < t2.y;
};

struct Edge
{
  int t1, t2, cost;
  Edge(int _t1, int _t2, int _cost):t1(_t1),t2(_t2),cost(_cost){};
  bool operator<(const Edge& t) const
  {
    return cost < t.cost;
  };
};

int root[100000];

int find_root(int x)
{
  return (root[x] == x)? x : (root[x] = find_root(root[x]));
}

void unite(int t1, int t2)
{
  root[find_root(t1)] = find_root(t2);
}

int main(int argc, char *argv[])
{
  int n;
  Town t[100000];
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> t[i].x >> t[i].y;
    t[i].id = root[i] = i;
  }

  vector<Edge> e;
  sort(t, t + n, comp_x);
  for (int i = 0; i < n-1; ++i) {
    e.push_back(Edge(t[i].id, t[i+1].id, t[i+1].x - t[i].x));
  }
  sort(t, t + n, comp_y);
  for (int i = 0; i < n-1; ++i) {
    e.push_back(Edge(t[i].id, t[i+1].id, t[i+1].y - t[i].y));
  }

  sort(e.begin(), e.end());
  int cost = 0;
  for (vector<Edge>::iterator it = e.begin(); it != e.end(); ++it) {
    if (find_root(it->t1) == find_root(it->t2)) continue;
    unite(it->t1, it->t2);
    cost += it->cost;
  }
  cout << cost << endl;
  return 0;
}
