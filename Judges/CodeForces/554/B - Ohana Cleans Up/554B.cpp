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

int main() {
  int n;
  cin >> n;
  msi m;
  for(int i = 0; i < n; ++i) {
    string line;
    cin >> line;
    m[line]++;
  }
  msi::iterator it;
  int ans = 0;
  for(it = m.begin(); it != m.end(); ++it) ans = max(ans, it -> second);
  cout << ans << endl;
  return 0;
}
