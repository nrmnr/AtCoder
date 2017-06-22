#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
  int n;
  cin >> n;
  string s;
  cin >> s;

  string ts = s;
  for (;;) {
    size_t pos = ts.find("()");
    if (pos == string::npos) break;
    ts.replace(pos, 2, "");
  }

  int cb = 0, ce = 0;;
  for (string::iterator i = ts.begin(); i != ts.end(); ++i) {
    (*i == '(')? cb++ : ce++;
  }
  s = string(ce, '(') + s + string(cb, ')');
  cout << s << endl;
  return 0;
}
