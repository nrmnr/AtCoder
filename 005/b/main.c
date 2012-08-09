#include <stdio.h>
int main()
{
	int i,x,y,dx,dy;
	char ds[3],tbl[9][10];
	scanf("%d%d%s\n",&x,&y,ds);
	--x; --y;
	dx = (ds[0]=='L'||ds[1]=='L')? -1 : ((ds[0]=='R'||ds[1]=='R')? 1 : 0);
	dy = (ds[0]=='U'||ds[1]=='U')? -1 : ((ds[0]=='D'||ds[1]=='D')? 1 : 0);
	for(i=0;i<9;++i){
		gets(tbl[i]);
	}
	for(i=0;i<4;++i,x+=dx,y+=dy){
		putchar(tbl[y][x]);
		if((x==0 && dx<0)||(x==8 && dx>0)) dx *= -1;
		if((y==0 && dy<0)||(y==8 && dy>0)) dy *= -1;
	}
	putchar('\n');
	return 0;
}
