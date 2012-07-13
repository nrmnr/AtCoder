#include <stdio.h>
int main()
{
	int y, m, d, c[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	scanf("%d/%d/%d",&y,&m,&d);
	for(;y%(m*d);){
		int dm = c[m];
		int is_leap = (!(y%400) || (!(y%4) && y%100));
		if(is_leap && (m == 2)) ++dm;
		++d;
		if(d > dm){
			d = 1; ++m;
		}
		if(m > 12){
			m = 1; ++y;
		}
	}
	printf("%04d/%02d/%02d\n",y,m,d);
	return 0;
}
