#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
	int n;
	string line;
	cin >> n >> line;
	double s = 0;
	for (int i = 0; i < n; ++i) {
		char c = line.at(i);
		switch(c){
		case 'F': break;
		default: s += 4 - (c - 'A');
		}
	}
	cout << setprecision(12) << (double)s/n << endl;
	return 0;
}
