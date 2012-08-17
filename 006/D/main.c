#include <stdio.h>
char board[1000][1001];
char *abc[7][8] = {
	{
		".......",
		"...o...",
		"..o.o..",
		".o...o.",
		".ooooo.",
		".o...o.",
		"......."
	},
	{
		".......",
		".oooo..",
		".o...o.",
		".oooo..",
		".o...o.",
		".oooo..",
		"......."
	},
	{
		".......",
		"..ooo..",
		".o...o.",
		".o.....",
		".o...o.",
		"..ooo..",
		"......."
	}
};
int search(int n, int ratio, int rot, int sx, int sy){
	int x,y,rx,ry,tx,ty;
	char **c = abc[n];
	for(y=0;y<7;++y){
		for(x=0;x<7;++x){
			switch(rot){
			case 0: tx = x;   ty = y;   break;
			case 1: tx = 6-y; ty = x;   break;
			case 2: tx = 6-x; ty = 6-y; break;
			case 3: tx = y;   ty = 6-x; break;
			}
			for(ry=0;ry<ratio;++ry){
				for(rx=0;rx<ratio;++rx){
					if(c[ty][tx] != board[sy+y*ratio+ry][sx+x*ratio+rx]) return 0;
				}
			}
		}
	}
	for(y=0;y<ratio*7;++y){
		for(x=0;x<ratio*7;++x){
			board[sy+y][sx+x] = 'x';
		}
	}
	return 1;
};
int main()
{
	int i,h,w;
	scanf("%d%d\n",&h,&w);
	for(i=0;i<h;++i){
		gets(board[i]);
	}
	int n=(h<w)?h:w;
	int r,x,y,rot,c[3]={0};
	for(r=1;r<=n/7;++r){
		for(y=0;y<=h-r*7;++y){
			for(x=0;x<=w-r*7;++x){
				for(rot=0;rot<4;++rot){
					for(i=0;i<3;++i){
						if(search(i,r,rot,x,y)) c[i]++;
					}
				}
			}
		}
	}
	printf("%d %d %d\n",c[0],c[1],c[2]);
	return 0;
}
