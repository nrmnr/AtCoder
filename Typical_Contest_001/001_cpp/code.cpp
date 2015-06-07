#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Point
{
  int x, y;
  Point(int _x, int _y) : x(_x), y(_y) {}
};

void stack_point(vector<string>& c, vector<Point>& stack, int x, int y)
{
  if (c[y][x] != '#') {
    stack.push_back(Point(x, y));
  }
}

bool solve(vector<string>& c, Point& s)
{
  vector<Point> stack;
  stack.push_back(s);
  for (; !stack.empty();) {
    Point p = stack.back();
    stack.pop_back();
    if (c[p.y][p.x] == 'g') return true;
    c[p.y][p.x] = '#';
    stack_point(c, stack, p.x-1, p.y);
    stack_point(c, stack, p.x, p.y-1);
    stack_point(c, stack, p.x, p.y+1);
    stack_point(c, stack, p.x+1, p.y);
  }
  return false;
}

int main(int argc, char *argv[])
{
  int h, w;
  cin >> h >> w;
  Point s(0,0);
  vector<string> c;
  c.push_back(string(w+2, '#'));
  for (int y = 1; !cin.eof(); ++y) {
    string row;
    cin >> row;
    if (row.empty()) continue;
    row = "#" + row + "#";
    c.push_back(row);
    int x = static_cast<int>(row.find('s', 0));
    if (x != string::npos) {
      s.x = x;
      s.y = y;
    }
  }
  c.push_back(string(w+2, '#'));

  cout << (solve(c, s) ? "Yes" : "No") << endl;

  return 0;
}
