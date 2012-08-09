#include <iostream>
using namespace std;
long long gcd(long long a, long long b){
	long long t;
	for(; a; t=b, b=a, a=t%a);
	return b;
}
int main()
{
	char c;
	long long x, y, z, g, m, n, s;
	cin >> x >> c >> y;
	g = gcd(x, y);
	x /= g; y /= g;

	bool f = false;
	for(int i = 0; i < 2; ++i){
		z = (2*x)/(y*y) + i;
		n = z*y;
		s = n*(n+1)/2;
		m = s - z*x;
		if(0 < m && m <= n){
			cout << n << " " << m << endl;
			f = true;
		}
	}
	if(!f){
		cout << "Impossible" << endl;
	}
	return 0;
}
