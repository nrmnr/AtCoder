#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int s[]={0,0,0,0};
	string l;
	getline(cin,l);getline(cin,l);
	for(int i=0;i<l.size();++i){
		s[l[i]-'1']++;
	}
	sort(s,s+4);
	cout << s[3] << " " << s[0] << endl;
	return 0;
}
