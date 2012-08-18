#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct P{ int x, y; P(int _x, int _y):x(_x),y(_y){}; };

vector<string> board;
int h, w;

int count_destroy(P p){
	if(board[p.y][p.x] == '#') return 0;
	int c = 0;
	for(int x = 0; x < w; ++x){
		if(board[p.y][x] == '#') ++c;
	}
	for(int y = 0; y < h; ++y){
		if(board[y][p.x] == '#') ++c;
	}
	return c;
};

P find_bomb_point(){
	int m = 0;
	P p(-1,-1);
	for(int y = 0; y < h; ++y){
		for(int x = 0; x < w; ++x){
			if(board[y][x] == '#') continue;
			int tm = count_destroy(P(x,y));
			if(tm > m){
				m = tm;
				p.x = x; p.y = y;
			}
		}
	}
	return p;
};

void bomb(P p){
	if(board[p.y][p.x] == '#') return;
	for(int x = 0; x < w; ++x){
		board[p.y][x] = '.';
	}
	for(int y = 0; y < h; ++y){
		board[y][p.x] = '.';
	}
};

bool all_clear(){
	for(int y = 0; y < h; ++y){
		for(int x = 0; x < w; ++x){
			if(board[y][x] == '#') return false;
		}
	}
	return true;
};

int main(){
	cin >> h >> w;
	bool filled = true, empty = true;
	for(int i=0;i<h;++i){
		string line;
		cin >> line;
		if(line.find('.') != string::npos) filled = false;
		if(line.find('#') != string::npos) empty = false;
		board.push_back(line);
	}
	if(filled){
		cout << -1 << endl;
		return 0;
	} else if(empty){
		cout << 0 << endl;
		return 0;
	}

	int c = 0;
	for(;!all_clear();++c){
		P p = find_bomb_point();
		bomb(p);
	}
	cout << c << endl;
	return 0;
}
