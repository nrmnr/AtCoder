#include <iostream>
#include <cstdin>

using namespace std;

char *board;
int rows, cols;

void load_board()
{
	scanf("%d%d\n", &rows, &cols);
	board = new char[rows * cols];
	string line;
	for (; !getline(cin, line).eof(); ) {
		for (int i = 0; i < cols; ++i) {
			
		}
	}
}

int main(int argc, char *argv[])
{
	if (board) {
    delete [] board;
	}
	return 0;
}
