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
#define D(x) cout << #x << " " << x << endl;

#define MAXN 105
char board[MAXN][MAXN];
int ans, bsize;

void dfs(int i, int j) {
  board[i][j] = 'b';
  if(i - 1 >= 0 && board[i - 1][j] == '-') {
    ans++;
    dfs(i - 1, j);
  }
  if((i - 1 >= 0 && j - 1 >= 0) && board[i - 1][j - 1] == '-') {
    ans++;
    dfs(i - 1, j - 1);
  }
  if((i - 1 >= 0 && j + 1 < bsize) && board[i - 1][j + 1] == '-') {
    ans++;
    dfs(i - 1, j + 1);
  }
  if(j - 1 >= 0 && board[i][j - 1] == '-') {
    ans++;
    dfs(i, j - 1);
  }
  if((i + 1 < bsize && j - 1 >= 0) && board[i + 1][j - 1] == '-') {
    ans++;
    dfs(i + 1, j - 1);
  }
  if(i + 1 < bsize && board[i + 1][j] == '-') {
    ans++;
    dfs(i + 1, j);
  }
  if((i + 1 < bsize && j + 1 < bsize) && board[i + 1][j + 1] == '-') {
    ans++;
    dfs(i + 1, j + 1);
  }
  if(j + 1 < bsize && board[i][j + 1] == '-') {
    ans++;
    dfs(i, j + 1);
  }
}

int main(){
  int t;
  cin >> t;
  while(t--) {
      cin >> bsize;
      ans = 0;
      for(int i = 0; i < bsize; ++i) {
        string line;
        cin >> line;
        for(int j = 0; j < line.size(); ++j) {
          board[i][j] = line[j];
        }
      }
      for(int i = 0; i < bsize; ++i) {
        for(int j = 0; j < bsize; ++j) {
          if(board[i][j] == 'w') {
            dfs(i, j);
          }
        }
      }
      cout << ans << endl;
  }
	return 0;
}
