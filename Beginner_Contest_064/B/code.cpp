#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
  int n;
  int a[100] = {0};
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a + n);
  cout << (a[n-1] - a[0]) << endl;
  return 0;
}
