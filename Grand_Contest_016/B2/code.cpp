#include <iostream>
#include <algorithm>
using namespace std;

bool judge() {
  int n, a[100000];
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  int nmin = n, nmax = 0;
  for (int i = 0; i < n; ++i) {
    nmin = min(nmin, a[i]);
    nmax = max(nmax, a[i]);
  }

  if (nmax - nmin > 1) return false;
  if (nmin == nmax) {
    return (nmin == n - 1 || (nmin >= 1 && nmin * 2 <= n));
  }

  int alone = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == nmin) alone++;
  }
  return (alone < nmax && (nmax - alone) * 2 <= n - alone);
}

int main(int argc, char *argv[])
{
  cout << (judge()? "Yes" : "No") << endl;
  return 0;
}
