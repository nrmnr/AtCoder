#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

struct Range
{
	long l;
	long r;
	Range(long l, long r){ this->l = l; this->r = r; }
};
vector<Range> ranges;

double calc_dist(long r_min, long r_max, long start, long goal)
{
	const double dx = goal - start;
	const double dy = r_max - r_min;

	if (r_min == r_max) {
		return 0;
	} else if (r_max - r_min == 1) {
		return hypot(dx, dy);
	}

	for (long row = r_min; row <= r_max; ++row) {
		const Range rng = ranges[row];
		const double pass = start + dx * (row - r_min) / dy;
		if (pass < rng.l) {
			return
				calc_dist(r_min, row, start, rng.l) +
				calc_dist(row, r_max, rng.l, goal);
		} else if (pass > rng.r) {
			return
				calc_dist(r_min, row, start, rng.r) +
				calc_dist(row, r_max, rng.r, goal);
		}
	}
	return hypot(dx, dy);
}

int main()
{
	long n, start, goal;
	cin >> n >> start >> goal;

	for(++n;n-->0;){
		long l, r;
		cin >> l >> r;
		ranges.push_back(Range(l,r));
	}

	cout << fixed << setprecision(11)
			 << calc_dist(0, ranges.size()-1, start, goal)
			 << endl;
	return 0;
}
