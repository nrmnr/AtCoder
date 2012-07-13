#include <cstdio>
#include <cfloat>
#include <cmath>
#include <iostream>
#include <vector>

struct Range
{
	long l;
	long r;
	Range(long l, long r){ this->l = l; this->r = r; }
};

int main()
{
	long n, start, goal;
	std::cin >> n >> start >> goal;

	std::vector<Range> ranges;
	ranges.reserve(n+1);
	for (long i = 0; i <= n; ++i) {
		long l, r;
		std::cin >> l >> r;
		ranges.push_back(Range(l,r));
	}
	ranges[n] = (Range(goal,goal));

	double l_view_angle = -DBL_MAX;
	double r_view_angle = DBL_MAX;
	long l_wall_y = 0, r_wall_y = 0;
	double dist = 0;
	long turning_y = 0;
	for (long y = 1; y <= n; ++y) {
		const Range rng = ranges[y];
		double l_va = (double)(rng.l - start) / (y - turning_y);
		if (l_va > l_view_angle) {
			l_view_angle = l_va;
			l_wall_y = y;
		}
		double r_va = (double)(rng.r - start) / (y - turning_y);
		if (r_va < r_view_angle) {
			r_view_angle = r_va;
			r_wall_y = y;
		}
		if (l_view_angle > r_view_angle) {
			long x;
			if (y == r_wall_y) {
				x = ranges[l_wall_y].l;
				y = l_wall_y;
			} else {
				x = ranges[r_wall_y].r;
				y = r_wall_y;
			}
			dist += hypot(x - start, y - turning_y);
			start = x; turning_y = y;
			l_view_angle = -DBL_MAX;
			r_view_angle = DBL_MAX;
		}
	}
	dist += hypot(goal - start, n - turning_y);
	printf("%.12lf\n", dist);
	return 0;
}
