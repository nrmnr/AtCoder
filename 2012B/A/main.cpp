#include <iostream>
using namespace std;
int main(){
	int a,b,c;
	cin >> a >> b >> c;
	for(int n=1;n<=127;++n){
		if(n%3==a && n%5==b && n%7==c)
			cout << n << endl;
	}
	return 0;
}
