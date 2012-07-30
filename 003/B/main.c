#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char buf[2100];
char *words[100];
int comp(const void *l, const void *r) {
	return strcmp(*(const char**)l, *(const char**)r);
}
int rev(char *s) {
	int len = strlen(s);
	char *l = s + (len - 1);
	for(; s < l; ++s, --l){
		char t = *s; *s = *l; *l = t;
	}
	return len;
}
int main()
{
	int i,n;
	scanf("%d\n", &n);
	char *p = buf;
	for(i=0; i<n; ++i){
		words[i] = p;
		p += rev(gets(p)) + 1;
	}
	qsort(words, n, sizeof(char*), comp);
	for(i=0; i<n; ++i){
		rev(words[i]);
		printf("%s\n", words[i]);
	}
	return 0;
}
