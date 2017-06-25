#include <iostream>
using namespace std;

int abs(int v) {
  return (v < 0)? -v : v;
}

const int mod = 1e9 + 7;
long long int fact[100000];
void init(int n) {
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = (fact[i-1] * i) % mod;
  }
}

int main(int argc, char *argv[])
{
  int n, m;
  cin >> n >> m;
  if (abs(n-m) > 1) {
    cout << 0 << endl;
    return 0;
  }
  init(n < m ? m : n);

  if (n == m) {
    long long int a = (((fact[n] * fact[m]) % mod) * 2) % mod;
    cout << a << endl;
    return 0;
  }

  long long int a = (fact[n] * fact[m]) % mod;
  cout << a << endl;
  return 0;
}
