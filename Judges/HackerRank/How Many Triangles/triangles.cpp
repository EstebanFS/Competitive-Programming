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

#define ll long long
#define D(x) cout << #x << " " << x << endl;
#define MAXN 10005

inline int h(double x, double y) {return sqrt((x * x) + (y * y));}

int main() {
  int n;
  while(cin >> n) {
    int triangles[MAXN];
    int dp[MAXN];
    memset(dp, 0, MAXN);
    int maxi = 0;
    for(int i = 0; i < n; ++i) {
      cin >> triangles[i];
      dp[triangles[i]] = i + 1;
      maxi = max(maxi, triangles[i]);
    }
    for(int i = 1; i < MAXN; ++i) {
      if(dp[i] != 0) continue;
      dp[i] = dp[i - 1];
    }
    for(int i = 0; i < )
    int acute = 0, right = 0, obtuse = 0;
    for(int i = 0; i < n; ++i) {
      int first = triangles[i];
      for(int j = i + 1; j < n; ++j) {
        int second = triangles[j];
        int maxValue = first + second;
        double hipo = h(first, second);
        if(hipo == floor(hipo)) {
          if(dp[(int)hipo] != dp[(int)hipo - 1]) right++;
          acute += dp[(int)hipo - 1];
          obtuse += ((dp[first + second - 1]) - dp[(int)hipo]);
        } else {
          acute += dp[(int)hipo];
          obtuse += ((dp[first + second - 1]) - dp[(int)hipo]);
        }
      }
    }
    printf("%d %d %d\n", acute, right, obtuse);
  }
}
