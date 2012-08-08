#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i,n,c;
	char line[101], *p = line;
	char *words[50] = {NULL};
	scanf("%d\n", &n);
	gets(line);
	words[0] = line;
	for(i=1; *p != '.'; ++p){
		if(*p == ' '){
			*p = '\0';
			words[i++] = p+1;
		}
	}
	*p = '\0';
	for(c=i=0; i<n; ++i){
		if(strcmp(words[i], "TAKAHASHIKUN") == 0 ||
			 strcmp(words[i], "Takahashikun") == 0 ||
			 strcmp(words[i], "takahashikun") == 0){
			++c;
		}
	}
	printf("%d\n", c);
	return 0;
}
