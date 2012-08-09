#include <stdio.h>
int h, w;
char map[500][501];
int direc[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
void show(){
	int i;
	for(i=0;i<h;++i) printf("%s\n",map[i]);
	printf("\n");
}
int solv(int x, int y, int d){
	if(x<0||w<=x||y<0||h<=y||map[y][x]=='x') return 0;
	/*show();*/
	if(map[y][x]=='g') return 1;
	int r;
	if(map[y][x]=='#'){
		if(d<=0) return 0;
		map[y][x] = '.';
		r = solv(x,y,d-1);
		map[y][x] = '#';
		return r;
	}
	int i;
	map[y][x] = 'x';
	for(i=0;i<4;++i){
		r = solv(x+direc[i][0], y+direc[i][1], d);
		if(r==1) return r;
	}
	map[y][x] = '.';
	return 0;
}
int main()
{
	int i,x=-1,y=-1;
	scanf("%d%d\n",&h,&w);
	for(i=0;i<h;++i){
		char *p = gets(map[i]);
		if(x>=0) continue;
		for(; *p; ++p){
			if(*p == 's'){
				x = p-map[i];
				y = i;
				break;
			}
		}
	}
	printf(solv(x,y,2)? "YES\n":"NO\n");
	return 0;
}
