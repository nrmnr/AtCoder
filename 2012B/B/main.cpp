#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	char line[51], back[51];
	gets(line);
	strcpy(back, line);
	int l = strlen(line);
	int s = 0;
	for(;line[s]=='_';++s);
	int e = 0;
	for(;line[l-e-1]=='_';++e);

	bool is_snake = false;
	bool is_camel = false;
	for(int i=s; i<l-e; ++i){
		if(line[i]=='_'){
			is_snake = true;
		} else if(isupper(line[i])){
			is_camel = true;
		}
	}

	if(!islower(back[s]) || s >= l || e >= l || (is_snake && is_camel)){
		puts(back);
		return 0;
	}

	for(int i=0;i<s;++i){
		putchar('_');
	}
	putchar(line[s]);
	char buf[51] = {'\0'};
	for(int i=s+1,j=0;i<l-e;++i){
		if(line[i]=='_'){
			if(!islower(line[i+1])){
				puts(line+(s+1));
				return 0;
			} else {
				buf[j++] = toupper(line[i+1]);
				++i;
			}
		} else if(isupper(line[i])){
			buf[j++] = '_';
			buf[j++] = tolower(line[i]);
		} else {
			buf[j++] = line[i];
		}
	}
	printf(buf);
	for(int i=0;i<e;++i) putchar('_');
	printf("\n");
	return 0;
}
