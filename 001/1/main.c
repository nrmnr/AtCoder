#include "stdio.h"
int main()
{
	int n,c[]={0,0,0,0},mx=0,mn=0;
	scanf("%d\n",&n);
	for(;n-->0;){
		c[getchar()-'1']++;
	}
	for(n=0;n<4;++n){
		if(c[n]>c[mx])mx=n;
		if(c[n]<c[mn])mn=n;
	}
	printf("%d %d\n",c[mx],c[mn]);
	return 0;
}
