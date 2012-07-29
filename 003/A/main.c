#include <stdio.h>
int main()
{
	int i,n,s,c;
	scanf("%d\n",&n);
	for (s = i = 0; i < n; ++i) {
		c = getchar();
		switch(c){
		case 'F': break;
		default:
			s += 4 - (c - 'A');
		}
	}
	printf("%.12f\n", (double)s/n);
	return 0;
}
