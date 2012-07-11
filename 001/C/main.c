#include <stdio.h>
char board[8]; // bit flags
void on(int x, int y){ board[y] |= (1<<x); }
void off(int x, int y){ board[y] &= ~(1<<x); }
int is_on(int x, int y){ return board[y] & (1<<x); }
void load_board()
{
	char l[10];
	int y=0, x;
	for(;~scanf("%s",l)&&y<8;++y){
		for(x=0;x<8;++x){
			if(l[x]=='Q') on(x,y);
		}
	}
}
void show_board()
{
	int x,y;
	for(y=0;y<8;++y){
		for(x=0;x<8;++x){
			putchar(is_on(x,y)?'Q':'.');
		}
		puts("");
	}
}
int is_enable_line(int x, int y, int dx, int dy)
{
	x+=dx; y+=dy;
	for(;0<=x&&x<8&&0<=y&&y<8;x+=dx,y+=dy){
		if(is_on(x,y)) return 0;
	}
	return 1;
}
int is_enable(int x, int y)
{
	return
		is_enable_line(x,y, 1, 0) &&
		is_enable_line(x,y,-1, 0) &&
		is_enable_line(x,y, 0, 1) &&
		is_enable_line(x,y, 0,-1) &&
		is_enable_line(x,y, 1, 1) &&
		is_enable_line(x,y,-1, 1) &&
		is_enable_line(x,y, 1,-1) &&
		is_enable_line(x,y,-1,-1);
}
int is_valid()
{
	int x,y;
	for(y=0;y<8;++y){
		for(x=0;x<8;++x){
			if(is_on(x,y) && !is_enable(x,y)) return 0;
		}
	}
	return 1;
}
int solve(int y)
{
	if(y==8) return 1;
	if(board[y]!=0){
		return solve(y+1);
	} else {
		int x;
		for(x=0;x<8;++x){
			if(is_enable(x,y)){
				on(x,y);
				if(solve(y+1)) return 1;
				off(x,y);
			}
		}
		return 0;
	}
}
int main()
{
	load_board();
	if(is_valid() && solve(0)){
		show_board();
	} else {
		puts("No Answer");
	}
	return 0;
}
