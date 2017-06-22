#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
  int a, b, c;
  cin >> a >> b >> c;
  cout << (!((a*100 + b*10 + c) % 4)? "YES" : "NO") << endl;
  return 0;
}
