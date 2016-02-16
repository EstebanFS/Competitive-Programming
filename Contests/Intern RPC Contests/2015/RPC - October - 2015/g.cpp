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
#include <limits>
#include <cfloat>

using namespace std;

typedef long long ll;
#define D(x) cout << #x << " " << x << endl
const double EPS = 1e-9;

struct toy {
  ll s, p;
  double r;
  toy(const int _s, const int _p, const double _r) {
    s = _s;
    p = _p;
    r = _r;
  }
  bool operator < (const toy &than) const {
    if(s < than.s) return true;
    else if (s == than.s) return p < than.p;
    return false;
  }
};

vector <toy> toys;

int main() {
  int n, k, x = 1;
  while(cin >> n >> k) {
    if(n == 0 && k == 0) break;
    toys.clear();
    for(int i = 0; i < n; ++i) {
      ll si, pi;
      cin >> si >> pi;
      double ratioToy = (pi * 1.0) / (si * 1.0);
      toy t = toy(si, pi, ratioToy);
      toys.push_back(t);
    }
    sort(toys.begin(), toys.end());
    //for(int i = 0; i < n; ++i) printf("s: %d  and p: %d with i: %d\n", toys[i].s, toys[i].p, i);
    //for(int i = 0; i < n; ++i) printf("ratioToy: %f with i: %d\n",ratioToys[i].r, ratioToys[i].index);
    ll sum = 0LL;
    for(int i = 0; i < k - 1; ++i) sum += toys[i].s;
    double ans = DBL_MAX;
    for(int i = k - 1; i < n; ++i) ans = min(ans, ((sum + toys[i].s) * 1.0) * toys[i].r);
    printf("Case #%d: %.6f\n", x++, ans);
  }
  return 0;
}
