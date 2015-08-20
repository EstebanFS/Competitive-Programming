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

#define ll long long
#define MAXN 100001
int items[MAXN];
int counti[MAXN];

int main() {
  int t;
  cin >> t;
  vector <int> perm;
  vector <int> missing;
  for(int i = 1; i <= t; ++i) {
    items[i] = 0;
    counti[i] = 0;
  }
  for(int i = 1; i <= t; ++i) {
    int n;
    cin >> n;
    items[n]++;
    perm.push_back(n);
  }
  for(int i = 1; i <= t; ++i) if(items[i] == 0) missing.push_back(i);
  int x = 0;
  for(int i = 0; i < t; ++i) {
    counti[perm[i]]++;
    if(counti[perm[i]] != 1 || perm[i] > t) {
      perm[i] = missing[x];
      x++;
    }
  }
  cout << perm[0];
  for(int i = 1; i < t; ++i) cout << " " << perm[i];
  cout << endl;
  return 0;
}
