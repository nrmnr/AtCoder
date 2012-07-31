#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct Point { int r; int c; double bright; };
bool operator<(const Point& p1, const Point& p2){
	return p1.bright < p2.bright;
};
Point dpt[4] = {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0}};

int main()
{
	priority_queue<Point> brightness;
	int R, C;
	cin >> R >> C;
	vector<string> map(R+2, string(C+2, '#'));
	for(int r = 1; r <= R; ++r){
		for(int c = 1; c <= C; ++c){
			cin >> map[r][c];
			if(map[r][c] == 'g'){
				Point g = {r, c, 1000};
				brightness.push(g);
				map[r][c] = '#';
			}
		}
	}

	for(;!brightness.empty();){
		Point pt = brightness.top();
		brightness.pop();
		for(int i = 0; i < 4; ++i){
			Point next = pt;
			next.r += dpt[i].r;
			next.c += dpt[i].c;
			char &nc = map[next.r][next.c];
			if(nc == '#') continue;
			if(nc == 's'){
				cout << setprecision(12) << pt.bright * 0.99 << endl;
				return 0;
			}
			next.bright = min(pt.bright * 0.99, (double)(nc - '0'));
			nc = '#';
			brightness.push(next);
		}
	}

	cout << -1 << endl;
	return 0;
}
