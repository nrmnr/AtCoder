#include <stdio.h>
int main()
{
	int i,n,l;
	char line[20],t,s[]={1,2,3,4,5,6,7,8,9,10};
	scanf("%d%d\n",&n,&l);
	for(;l-->0;){
		gets(line);
		for(i=0;i<n-1;++i){
			if(line[2*i+1] == '-'){
				t = s[i]; s[i] = s[i+1]; s[i+1] = t;
			}
		}
	}
	gets(line);
	for(i=0;i<n;++i){
		if(line[2*i] == 'o'){
			printf("%d\n",s[i]);
			break;
		}
	}
	return 0;
}
