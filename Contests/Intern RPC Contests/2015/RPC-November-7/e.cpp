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

int main() {
  int n;
  while(cin >> n) {
    int times[n];
    for(int i = 0; i < n; ++i) cin >> times[i];
    sort(times, times + n);
    int leftSide = n;
    ll ans = 0L;
    while(leftSide > 2) {
      ans += times[0] + times[1] * 2 + times[leftSide - 1];
      D(ans); D(times[leftSide - 1]);
      leftSide -= 2;
    }
    ans += times[1];
    cout << ans << endl;
  }
}
