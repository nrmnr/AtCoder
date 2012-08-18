#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct P{ int x, y; P(int _x, int _y):x(_x),y(_y){}; };

vector<string> board;
int h, w;

bool can_destroy(P p){
	if(board[p.y][p.x] == '#') return false;
	for(int x = 0; x < w; ++x){
		if(board[p.y][x] == '#') return true;
	}
	for(int y = 0; y < h; ++y){
		if(board[y][p.x] == '#') return true;
	}
	return false;
};

P find_bomb_point(){
	for(int y = 0; y < h; ++y){
		for(int x = 0; x < w; ++x){
			if(board[y][x] == '.' && can_destroy(P(x,y))){
				return P(x,y);
			}
		}
	}
	return P(-1,-1);
};

void bomb(P p, vector<P>& destroy){
	if(board[p.y][p.x] == '#') return;
	for(int x = 0; x < w; ++x){
		if(board[p.y][x] == '#'){
			board[p.y][x] = '.';
			destroy.push_back(P(x,p.y));
		}
	}
	for(int y = 0; y < h; ++y){
		if(board[y][p.x] == '#'){
			board[y][p.x] = '.';
			destroy.push_back(P(p.x,y));
		}
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

int solv(int c){
	if(all_clear()) return c;
	P p = find_bomb_point();
	if(p.x == -1) return 1e9;

	board[p.y][p.x] = 'x';
	int tc1 = solv(c);
	board[p.y][p.x] = '.';

	vector<P> destroy;
	bomb(p, destroy);
	int tc2 = solv(c+1);
	for(; !destroy.empty(); destroy.pop_back()){
		P p = destroy.back();
		board[p.y][p.x] = '#';
	}

	return min(tc1, tc2);
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

	cout << solv(0) << endl;
	return 0;
}
