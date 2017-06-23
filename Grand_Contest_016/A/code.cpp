#include <iostream>
using namespace std;

int calc_max_part(const string& s, char target)
{
  int maxl = 0;
  for (size_t pos = 0, nextpos;; pos = nextpos + 1) {
    nextpos = s.find(target, pos);
    int l;
    if (nextpos == string::npos) {
      l = s.size() - pos;
    } else {
      l = nextpos - pos;
    }
    if (maxl < l) maxl = l;
    if (nextpos == string::npos) break;
  }
  return maxl;
}

int main(int argc, char *argv[])
{
  string s;
  cin >> s;
  int count[26] = {0};
  for (string::iterator c = s.begin(); c != s.end(); ++c) {
    count[*c - 'a']++;
  }

  int minl = s.size();
  for (char target = 'a'; target <= 'z'; ++target) {
    if (count[target - 'a'] > 0) {
      int l = calc_max_part(s, target);
      minl = (minl < l)? minl : l;
    }
  }

  cout << minl << endl;
  return 0;
}
