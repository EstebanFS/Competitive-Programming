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

#define MAXN 105
#define MAXS 10
#define D(x) cout << #x << " " << x << endl;

int main(){
  int t;
  cin >> t;
  map<char, int> colors;
  colors['b'] = 0;
  colors['g'] = 1;
  colors['r'] = 2;
  colors['y'] = 3;
  while(t--) {
      int tiles;
      cin >> tiles;
      int group[MAXN][MAXS], run[MAXS][MAXN];
      for(int i = 0; i < MAXN; ++i) {
        for(int j = 0; j < MAXS; ++j) {
          group[i][j] = 0;
          run[j][i] = 0;
        }
      }
      bool ans = false;
      for(int i = 0; i < tiles; ++i){
        string tile;
        cin >> tile;
        char suit = tile[tile.size() - 1];
        int pos = colors[suit];
        string snumber = tile.substr(0, tile.size() - 1);
        int number = toInt(snumber);
        if(group[number][pos] == 0) group[number][MAXS - 1]++;
        run[pos][number] = 1;
        group[number][pos] = 1;
      }
      for(int i = 0; i < MAXN && !ans; ++i) {
		      if(group[i][MAXS - 1] >= 3) ans = true;
      }
      for(int i = 0; i < MAXS && !ans; ++i) {
      	for(int j = 1; j < MAXN - 1 && !ans; ++j) {
          if(run[i][j] == 1 && (run[i][j - 1] == 1 && run[i][j + 1] == 1)) {
            ans = true;
          }
        }
      }
      if(ans) cout << "YES" << endl;
      else cout << "NO" << endl;
  }
	return 0;
}
