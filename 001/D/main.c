#include <stdio.h>
#include <math.h>
int main()
{
	int n,c,g,b,e,y=0,x;
	double d=0;
	scanf("%d\n%d%d",&n,&c,&g);
	printf("%d %d %d\n",n,c,g);
	++n;
	for(;n-->0;){
		scanf("%d%d",&b,&e);
		printf("%d:%d-%d\n",n,b,e);
	}
	printf("%lf\n",d);
	return 0;
}
