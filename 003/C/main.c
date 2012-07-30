#include <stdio.h>
typedef struct{
	int r; int c;
} Point;
char map[500][500];
int R,C;

double solv(int r, int c, double weight, double min) {
	if(r < 0 || R <= r || c < 0 || C <= c || map[r][c] == '#') return -1;
	if(map[r][c] == 'g') return min;
	if(map[r][c] != 's'){
		double light = (map[r][c] - '0') * weight;
		if(light < min) min = light;
	}
	double max=-1, l;
	Point n[4] = {{r-1,c}, {r+1,c}, {r,c-1}, {r,c+1}};
	int i;
	char b = map[r][c];
	map[r][c] = '#';
	for(i=0;i<4;++i){
		l = solv(n[i].r, n[i].c, weight*0.99, min);
		if(l>max) max = l;
	}
	map[r][c] = b;
	return max;
}

int main()
{
	int r,c;
	Point s;
	scanf("%d%d\n",&R,&C);
	char line[501];
	for(r=0;r<R;++r){
		gets(line);
		for(c=0;c<C;++c){
			map[r][c] = line[c];
			if(map[r][c]=='s'){
				s.r = r;
				s.c = c;
			}
		}
	}

	double result = solv(s.r, s.c, 1.0, 10.0);
	if(result >= 0)
		printf("%.12f\n", result);
	else
		printf("-1\n");

	return 0;
}
