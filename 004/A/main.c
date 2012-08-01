#include <stdio.h>
#include <math.h>
int max(int a, int b){ return (a > b)? a : b; }
int dist(int dx, int dy){ return dx * dx + dy * dy; }
int main(int argc, char *argv[])
{
	int x[100], y[100], N, n, i, m = 0;
	scanf("%d", &N);
	for (n = 0; n < N; ++n) {
		scanf("%d%d", x+n, y+n);
		for (i = 0; i < n; ++i) {
			m = max(m, dist(x[n]-x[i], y[n]-y[i]));
		}
	}
	printf("%f\n", sqrt(m));
	return 0;
}
