#include <stdio.h>
int h,w,stack[1000000],*stp;
char board[1000][1001];
int count_aside(int sx, int sy){
	int c,dx,dy,stx,sty,x,y,st;
	stp = stack;
	*stp = sy * w + sx;
	board[sy][sx] = '.';
	for(c=1;stp>=stack;){
		st = *stp--;
		stx = st % w;
		sty = st / w;
		for(dy=-1;dy<=1;++dy){
			for(dx=-1;dx<=1;++dx){
				x = stx + dx;
				y = sty + dy;
				if(x<0||x>=w||y<0||y>=h||board[y][x]!='o') continue;
				board[y][x] = '.';
				*(++stp) = y * w + x;
				++c;
			}
		}
	}
	return c;
}
int main()
{
	int i;
	scanf("%d%d\n",&h,&w);
	for(i=0;i<h;++i){
		gets(board[i]);
	}
	int a,ca,r,x,y,c[3]={0};
	for(y=0;y<h;++y){
		for(x=0;x<w;++x){
			if(board[y][x]!='o') continue;
			ca = count_aside(x,y);
			for(r=1;;++r){
				if(ca % (r*r) != 0) continue;
				a = ca / (r*r);
				if(a==12){ c[0]++; break; }
				if(a==16){ c[1]++; break; }
				if(a==11){ c[2]++; break; }
			}
		}
	}
	printf("%d %d %d\n",c[0],c[1],c[2]);
	return 0;
}
