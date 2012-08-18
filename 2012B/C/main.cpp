#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Range
{
	int b, e; bool u;
	Range(int _b, int _e):b(_b),e(_e),u(false){};
};

bool overlap(const Range& l, const Range& r) {
	for(int f=-1; f<=1; ++f){
		Range tl(l.b+f*24*60, l.e+f*24*60);
		if((tl.b <= r.b && r.b <= tl.e) ||
			 (tl.b <= r.e && r.e <= tl.e) ||
			 (r.b <= tl.b && tl.b <= r.e) ||
			 (r.b <= tl.e && tl.e <= r.e))
			return true;
	}
	return false;
};

bool operator<(const Range& l, const Range& r) {
	return (l.b < r.b);
};

struct FindOverlap
{
	Range base;
	FindOverlap(const Range& r):base(r){};
	bool operator()(const Range& other) const {
		return overlap(base, other);
	};
};

int main(){
	int n;
	cin >> n;
	vector<Range> rngs;
	for(;n-->0;){
		char c;
		int tsh,tsm,teh,tem;
		cin >> tsh >> c >> tsm >> teh >> c >> tem;
		rngs.push_back(Range(tsh*60+tsm, teh*60+tem-1));
	}
	sort(rngs.begin(), rngs.end());
	int c = 0;
	for(vector<Range>::iterator r = rngs.begin(); r != rngs.end(); ++r){
		if(r->u) continue;
		r->u = true;
		++c;
		vector<Range> rsvs;
		rsvs.push_back(*r);
		for(vector<Range>::iterator o = rngs.begin(); o != rngs.end(); ++o){
			if(o->u) continue;
			if(find_if(rsvs.begin(), rsvs.end(), FindOverlap(*o)) == rsvs.end()){
				o->u = true;
				rsvs.push_back(*o);
			}
		}
	}
	cout << c << endl;
	return 0;
}
