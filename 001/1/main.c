#include "stdio.h"
int mx(int s[], int n){
	int m = 0;
	for (;n-->0;) {
		if (s[n] >= m) m = s[n];
	}
	return m;
}
int mn(int s[], int n){
	int m = 0xffff;
	for (;n-->0;) {
		if (s[n] <= m) m = s[n];
	}
	return m;
}
int main(){
	int c, s[]={0,0,0,0};
	scanf("%d", &c);
	for (;c=getchar(),~c;){
		if('1'<=c&&c<='4') s[c-'1']++;
	}
	printf("%d %d\n", mx(s,4), mn(s,4));
	return 0;
}
