#include <iostream>
using namespace std;
long long gcd(long long a, long long b){
	long long t;
	for(; a; t=b, b=a, a=t%a);
	return b;
}
int main()
{
	bool f = false;
	char c;
	long long x, y, g, z, m, n;
	cin >> x >> c >> y;
	g = gcd(x, y);
	x /= g; y /= g;

	n = 2*x/y;
	if((2*x)%y != 0) n++;

	z = ((n+1)*y-2*x)*n;
	if(z % (2*y) == 0){
		m = z / (2*y);
		cout << n << " " << m << endl;
		f = true;
	}
	++n;
	if(2*x == y*(n-1)){
		cout << n << " " << n << endl;
		f = true;
	}
	if(!f){
		cout << "Impossible" << endl;
	}
	return 0;
}
