#include <stdio.h>
int main()
{
	int f,t,d[]={0,1,2,3,2,1,2,3,3,2};
	scanf("%d%d",&f,&t);
	t=abs(t-f);
	printf("%d\n",t/10+d[t%10]);
	return 0;
}
