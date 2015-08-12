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
#define msi map <string, int>
#define MAXN 10
ll limit[MAXN];

void build() {
  limit[0] = 9;
  for(int i = 1; i < MAXN; ++i) limit[i] = limit[i - 1] * 10LL + 9LL;
}

int main() {
  build();
  string n;
  cin >> n;
  ll s = n.size();
  ll number = toInt(n);
  ll ans = 0;
  int less = s - 2;
  if(s >= 2) ans += 9;
  else {
  	cout << number << endl;
  	return 0;
  }
  ans = (number - limit[less]) * s;
  if(s >= 2) ans += 9LL;
  for(ll i = 1; i < s - 1; ++i) ans += (limit[i] - limit[i - 1]) * (i + 1LL);
  cout << ans << endl;
  return 0;
}
