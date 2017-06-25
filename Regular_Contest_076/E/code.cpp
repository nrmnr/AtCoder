#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

struct Point {
  int id, x, y, key;
  Point(int id = 0, int x = 0, int y = 0):id(id),x(x),y(y){};
  bool is_edge(int r, int c) const {
    return (x == 0 || x == r || y == 0 || y == c);
  };
  void calc_key(int r, int c) {
    if (y == 0) key = x;
    else if (x == r) key = r + y;
    else if (y == c) key = r + c + (r - x);
    else key = r + c + r + (c - y);
  };
};

struct Pred {
  bool operator()(const Point& pt1, const Point& pt2) const {
    return pt1.key < pt2.key;
  };
};

int main(int argc, char *argv[])
{
  int r, c, n;
  cin >> r >> c >> n;

  vector<Point> pts;
  pts.reserve(n);
  for (int i = 0; i < n; ++i) {
    Point pt1(i), pt2(i);
    cin >> pt1.x >> pt1.y >> pt2.x >> pt2.y;
    if (pt1.is_edge(r,c) && pt2.is_edge(r,c)) {
      pt1.calc_key(r, c); pt2.calc_key(r, c);
      pts.push_back(pt1);
      pts.push_back(pt2);
    }
  }
  if (pts.size() <= 2) {
    cout << "YES" << endl;
    return 0;
  }

  sort(pts.begin(), pts.end(), Pred());

  stack<int> st;
  set<int> flag;
  for (int i = 0; i < pts.size(); ++i) {
    int id = pts[i].id;
    if (flag.find(id) == flag.end()) {
      st.push(id);
      flag.insert(id);
    } else {
      if (st.top() != id) {
        cout << "NO" << endl;
        return 0;
      }
      st.pop();
    }
  }
  cout << "YES" << endl;
  return 0;
}
