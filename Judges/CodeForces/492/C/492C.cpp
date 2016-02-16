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

#define D(x) cout << #x << " " << x << endl
#define ll long long
const double EPS = 1e-9;

struct exam {
  ll a, b;
  exam(const int _a, const int _b) {
    a = _a;
    b = _b;
  }
  bool operator < (const exam &than) const {
    if (b < than.b) return true;
    else if (b == than.b) return a < than.a;
    else return false;
  }
};

int main() {
  ll n, r, ans = 0, avg, currAvg = 0;
  cin >> n >> r >> avg;
  vector<exam> exams;
  for(int i = 0; i < n; ++i) {
    ll ai, bi;
    cin >> ai >> bi;
    currAvg += ai;
    exams.push_back(exam(ai, bi));
  }
  sort(exams.begin(), exams.end());
  avg *= n;
  for(int i = 0; i < exams.size() && currAvg < avg; ++i) {
    exam curr = exams[i];
    ll needed = min(avg - currAvg, r - curr.a);
    ans += needed * curr.b;
    currAvg += needed;
  }
  cout << ans << endl;
}
