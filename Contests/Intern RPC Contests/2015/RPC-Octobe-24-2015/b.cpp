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
#define MAXN 7205
#define INF 3610
int dp[MAXN];

int main() {
  int n;
  cin >> n;
  while(n--) {
    int b, t;
    cin >> b >> t;
    vector<int> neg, pos;
    int maxB = 0;
    for(int i = 0; i < b; ++i) {
      int value;
      cin >> value;
      if(value > 0) {
        pos.push_back(value);
        maxB = max(maxB, value);
      }
      else if(value < 0) neg.push_back(value);
    }
    dp[0] = 0;
    for(int i = 1; i < MAXN; ++i) dp[i] = INF;
    for(int i = 0; i < pos.size(); ++i) {
      dp[pos[i]] = 1;
      for(int j = pos[i] + 1; j < MAXN; ++j) {
        dp[j] = min(dp[j], dp[j - pos[i]] + 1);
        if(j >= 3600) dp[3600] = min(dp[3600], dp[j]);
      }
    }
    for(int i = 0; i < neg.size(); ++i) {
      for(int j = abs(neg[i]) + 1; j <= 3600; ++j) {
        dp[j + neg[i]] = min(dp[j + neg[i]], dp[j] + 1);
      }
    }
    int buttons, extra;
    if(dp[t] != INF) {
      buttons = dp[t];
      extra = 0;
    } else {
      for(int i = t + 1; i <= 3600; ++i) {
        if(dp[i] != INF) {
          buttons = dp[i];
          extra = i - t;
          break;
        }
      }
    }
    printf("%d %d\n", buttons, extra);
  }
  return 0;
}
