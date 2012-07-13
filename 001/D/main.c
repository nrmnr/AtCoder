#include <stdio.h>
#include <math.h>
#include <float.h>
typedef struct
{
	int l; int r;
} Range;

int main()
{
	int n,start,goal;
	scanf("%d\n%d%d",&n,&start,&goal);
	//printf("%d %d %d\n",n,c,g);
	Range ranges[200001];
	int i=0;
	for(; i<=n; ++i){
		int l, r;
		scanf("%d%d",&l,&r);
		//printf("%d:%d-%d\n",n,b,e);
		ranges[i].l = l; ranges[i].r = r;
	}
	ranges[n].l = ranges[n].r = goal;

	int x,y=1,ty=0;
	double lva = -DBL_MAX, rva = DBL_MAX;
	int lwy = 0, rwy = 0;
	double d=0, va;
	for(; y<=n; ++y){
		va = (double)(ranges[y].l - start) / (y - ty);
		if(va > lva){
			lva = va;
			lwy = y;
		}
		va = (double)(ranges[y].r - start) / (y - ty);
		if(va < rva){
			rva = va;
			rwy = y;
		}
		if(lva > rva){
			if(y == rwy){
				x = ranges[lwy].l;
				y = lwy;
			} else {
				x = ranges[rwy].r;
				y = rwy;
			}
			d += hypot(x-start, y-ty);
			start = x; ty = y;
			lva = -DBL_MAX; rva = DBL_MAX;
		}
	}
	d += hypot(goal-start, n-ty);
	printf("%.12lf\n",d);
	return 0;
}
