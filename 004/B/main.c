#include <stdio.h>
int main()
{
	int i, N, d, d_max, sum, min;
	scanf("%d", &N);
	for (i = d_max = sum = 0; i < N; ++i) {
		scanf("%d", &d);
		if (d > d_max) d_max = d;
		sum += d;
	}
	min = (d_max <= sum / 2)? 0 : d_max * 2 - sum;
	printf("%d\n%d\n", sum, min);
	return 0;
}
