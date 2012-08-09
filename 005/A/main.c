#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int i,n,c;
	char word[101] = {'\0'};
	scanf("%d\n", &n);
	for(c=i=0; i<n; ++i){
		scanf("%s", word);
		if(i==n-1){
			int l=strlen(word);
			word[l-1] = '\0';
		}
		if(strcmp(word, "TAKAHASHIKUN") == 0 ||
			 strcmp(word, "Takahashikun") == 0 ||
			 strcmp(word, "takahashikun") == 0){
			++c;
		}
	}
	printf("%d\n", c);
	return 0;
}
