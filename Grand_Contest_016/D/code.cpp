#include <iostream>
using namespace std;

int xor_arr(int v[], int n)
{
  int x = v[1];
  for (int i = 2; i <= n; ++i) {
    x = x ^ v[i];
  }
  return x;
}

int main(int argc, char *argv[])
{
  int n, a[100010], b[100010];
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i];
  a[0] = xor_arr(a, n);
  b[0] = xor_arr(b, n);
  cerr << a[0] << endl;

  return 0;
}
