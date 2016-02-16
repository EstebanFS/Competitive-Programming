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

int main() {
  int na, nb, k, m;
  cin >> na >> nb >> k >> m;
  int a[na], b[nb];
  for(int i = 0; i < na; ++i) cin >> a[i];
  for(int i = 0; i < nb; ++i) cin >> b[i];
  sort(a, a + na);
  sort(b, b + nb);
  if(a[k - 1] < b[nb - (m - 1) - 1]) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
