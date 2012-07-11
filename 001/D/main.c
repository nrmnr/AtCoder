#include <stdio.h>
#include <math.h>
int main()
{
	int n,c,g,b,e,y=0,x;
	double d=0;
	scanf("%d\n%d%d",&n,&c,&g);
	// printf("%d %d %d\n",n,s,g);
	++n;
	for(;n-->0;){
		scanf("%d%d",&b,&e);
		/*
		printf("%d:%d-%d:",n,b,e);
		if(b>g && b>c){
			x=b;
		}else if(e<g && e<c){
			x=e;
		}else if(n==0){
			x=g;
		}else{
			++y;
			printf("%d %d\n",x,y);
			continue;
		}
		printf("%d %d\n",x,y);
		d+=sqrt((x-c)*(x-c)+y*y);
		y=0;
		c=x;
		*/
	}
	printf("%lf\n",d);
	return 0;
}
