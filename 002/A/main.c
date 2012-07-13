#include <stdio.h>
int main()
{
	int y;
	scanf("%d",&y);
	printf("%s\n", (!(y%400) || (!(y%4) && y%100))? "YES":"NO");
	return 0;
}
