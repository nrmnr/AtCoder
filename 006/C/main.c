#include <stdio.h>
int main()
{
	int i,n,p=0,stack[50]={0};
	scanf("%d\n",&n);
	for(;scanf("%d\n",&n)==1;){
		for(i=0;i<p;++i){
			if(n<=stack[i]){
				stack[i] = n;
				break;
			}
		}
		if(i==p){
			stack[p] = n;
			++p;
		}
	}
	printf("%d\n",p);
	return 0;
}
