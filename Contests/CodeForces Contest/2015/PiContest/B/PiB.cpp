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
#define MAXN 1000005

int id[MAXN];

int main() {
  int n;
  cin >> n;
  int ans = 0;
  int inside = 0;
  bool left = false;
  for(int i = 0; i < MAXN; ++i) id[i] = 0;
  for(int i = 0; i < n; ++i) {
    char sign;
    int idVisitor;
    cin >> sign >> idVisitor;
    if(sign == '+') {
      id[idVisitor]++;
      inside++;
      ans = max(inside, ans);
    }
    else id[idVisitor]--;
    if(id[idVisitor] == 0) {
      left = true;
      inside--;
    }
    if(id[idVisitor] < 0) {
      ans++;
      id[idVisitor] = 0;
    }
  }
  cout << ans << endl;
  return 0;
}
