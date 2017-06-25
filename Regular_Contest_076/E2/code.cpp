#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

bool is_edge(int x, int y, int r, int c)
{
  return (x == 0 || x == r || y == 0 || y == c);
}

int key(int x, int y, int r, int c)
{
  if (y == 0) return x;
  if (x == r) return r + y;
  if (y == c) return r + c + (r - x);
  return r + c + r + (c - y);
}

struct Point {
  int key, id, flag;
  Point(int k, int i, bool f):key(k),id(i),flag(f){};
  bool operator<(const Point& p) const {
    return key < p.key;
  };
};

int main(int argc, char *argv[])
{
  int r, c, n;
  cin >> r >> c >> n;

  vector<Point> pts;
  pts.reserve(n);
  for (int i = 0; i < n; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (is_edge(x1,y1,r,c) && is_edge(x2,y2,r,c)) {
      int k1 = key(x1,y1,r,c);
      int k2 = key(x2,y2,r,c);
      pts.push_back(Point(min(k1,k2),i,true));
      pts.push_back(Point(max(k1,k2),i,false));
    }
  }

  sort(pts.begin(), pts.end());

  stack<int> st;
  for (vector<Point>::iterator pt = pts.begin(); pt != pts.end(); ++pt) {
    if (pt->flag) {
      st.push(pt->id);
    } else {
      if (st.top() != pt->id) {
        puts("NO");
        return 0;
      }
      st.pop();
    }
  }
  puts("YES");
  return 0;
}
