//Esteban Foronda Sierra
using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r;}

#define D(x) cout << #x " is " << x << endl


int eat(int y, int x, int ans, vector<string> board) {
	//printf("y: %d x: %d ans: %d\n", y, x, ans);
	int value[4];
	board[y][x] = '.';
	for(int i = 0; i < 4; ++i) value[i] = ans;
	if((y + 2 < 10 && x + 2 < 10) && (board[y + 1][x + 1] == 'B' && (board[y + 2][x + 2] != 'B' && board[y + 2][x + 2] != 'W'))){
		board[y + 1][x + 1] = '.';
		value[0] = eat(y + 2, x + 2, ans + 1, board);
		board[y + 1][x + 1] = 'B';
	}
	if((y + 2 < 10 && x - 2 >= 0) && (board[y + 1][x - 1] == 'B' && (board[y + 2][x - 2] != 'B' && board[y + 2][x - 2] != 'W'))) {
		board[y + 1][x - 1] = '.';
		value[1] = eat(y + 2, x - 2, ans + 1, board);
		board[y + 1][x - 1] = 'B';
	}
	if((y - 2 >= 0 && x + 2 < 10) && (board[y - 1][x + 1] == 'B' && (board[y - 2][x + 2] != 'B' && board[y - 2][x + 2] != 'W'))) {
		board[y - 1][x + 1] = '.';
		value[2] = eat(y - 2, x + 2, ans + 1, board);
		board[y - 1][x + 1] = 'B';
	}
	if((y - 2 >= 0 && x - 2 >= 0) && (board[y - 1][x - 1] == 'B' && (board[y - 2][x - 2] != 'B' && board[y - 2][x - 2] != 'W'))){
		board[y - 1][x - 1] = '.';
		value[3] = eat(y - 2, x - 2, ans + 1, board);
		board[y - 1][x - 1] = 'B';
	}
	return max(value[0], max(value[1], max(value[2], value[3])));
} 

int main() {
	int t;
	cin >> t;
	while(t--) {
		vector<string> board;
		for(int i = 0; i < 10; ++i) {
			string line;
			cin >> line;
			board.push_back(line);
		}
		int ans = 0;
		for(int i = 0; i < board.size(); ++i) {
			for(int j = 0; j < 10; ++j) {
				if(board[i][j] == 'W') {
					ans = max(ans, eat(i, j, 0, board));
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

