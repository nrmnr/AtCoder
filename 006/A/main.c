#include <stdio.h>

int main()
{
	int i,b,n,c,k[10] = {0};
	for(i=0;i<6;++i){
		scanf("%d",&n);
		k[n] = 1;
	}
	scanf("%d",&b);
	for(c=i=0;i<6;++i){
		scanf("%d",&n);
		if(k[n] == 1) ++c;
		else if(n == b) b = -1;
	}
	switch(c){
	case 6: puts("1"); break;
	case 5: {
		if(b == -1) puts("2");
		else puts("3");
		break;
	}
	case 4: puts("4"); break;
	case 3: puts("5"); break;
	default: puts("0");
	}
	return 0;
}
