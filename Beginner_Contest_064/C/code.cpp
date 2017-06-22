#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
  int n;
  cin >> n;
  int count[9] = {0};
  for (; n-->0;) {
    int i;
    cin >> i;
    i /= 400;
    if (i > 8) i = 8;
    count[i]++;
  }
  int v = 0;
  for(int i = 0; i < 8; ++i) {
    if (count[i] > 0) v++;
  }

  int mn, mx;
  mn = (v == 0)? 1 : v;
  mx = v + count[8];
  cout << mn << " " << mx << endl;
  return 0;
}
