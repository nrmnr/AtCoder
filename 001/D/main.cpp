#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct Range
{
	int l;
	int r;
	Range(int l, int r){ this->l = l; this->r = r; }
};
typedef vector<Range> Ranges;

Ranges ranges;

double calc_dist(int r_begin, int r_end, int start, int goal)
{
	for (int row = r_begin; row < r_end; ++row) {
		
	}
	return 0;
}

int main()
{
	int n, start, goal;
	cin >> n >> start >> goal;
	// cout << n << " " << c << " " << g << endl;
	++n;
	for(;n-->0;){
		int l, r;
		cin >> l >> r;
		ranges.push_back(Range(l,r));
		cout << n << ":" << l << "-" << r << endl;
	}
	cout << fixed << setprecision(11)
			 << calc_dist(0, ranges.size(), start, goal)
			 << endl;
	return 0;
}
