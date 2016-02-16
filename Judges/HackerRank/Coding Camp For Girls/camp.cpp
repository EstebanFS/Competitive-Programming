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
#define pii pair<int, int>
#define ppii pair<int, pii>
#define MAXN 10000005
int own[MAXN];

int main () {
  int n, m;
  while(cin >> n >> m) {
    vector<ppii> sets;
    for(int i = 0; i < m; ++i) {
      int l, r;
      cin >> l >> r;
      sets.push_back(ppii(r - l, pii(l, r)));
    }
    sort(sets.rbegin(), sets.rend());
    vector<pii> ans;
    for(int i = 0; i < sets.size(); ++i) {
      pii curr = sets[i].second;
      for(int j = curr.first; j <= curr.second; ++j) own[j] = i;
    }
    for(int i = 1; i < sets.size(); ++i) {
      pii curr = sets[i].second;
      for(int j = i - 1; j >= 0; --j) {
        pii biggerSet = sets[j].second;
        if(curr.first > biggerSet.first && curr.second < biggerSet.second) {
          if(own[curr.first - 1] == j) ans.push_back(pii(curr.first - 1, curr.first));
          if(own[curr.second + 1] == j) ans.push_back(pii(curr.second, curr.second + 1));
          break;
        }
      }
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", (int)ans.size());
    for(int i = 0; i < ans.size(); ++i) printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
