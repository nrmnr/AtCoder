#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
  int n;
  cin >> n;
  vector<int> a;
  for (; n-->0;) {
    int t; cin >> t;
    a.push_back(t);
  }

  int min = a.size(), max = 0;
  for (vector<int>::iterator ia = a.begin(); ia != a.end(); ++ia) {
    int i = *ia;
    min = (min > i)? i : min;
    max = (max < i)? i : max;
  }

  if (max - min > 1) {
    cout << "No" << endl;
    return 0;
  }

  if (max == min) {
    if (min == a.size() - 1 || min * 2 <= a.size()) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
    return 0;
  }

  // min == max - 1
  int alone = 0, notalone = 0;
  for (vector<int>::iterator ia = a.begin(); ia != a.end(); ++ia) {
    if (min == *ia) {
      alone++;
    } else {
      notalone++;
    }
  }
  if (alone < max && (max - alone) * 2 <= notalone) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
