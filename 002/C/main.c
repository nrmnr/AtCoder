#include <stdio.h>

int main()
{
	int i,n;
	scanf("%d\n",&n);
	if(n <= 2){printf("%d\n",1); return 0;}
	if(n <= 4){printf("%d\n",2); return 0;}

	char cmd[1001];
	gets(cmd);
	//printf("%s\n",cmd);

	return 0;
}
