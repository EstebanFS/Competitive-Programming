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
#define MAXN 5
int value[] = {500, 1000, 1500, 2000, 2500};

int main() {
  int mi[MAXN], wi[MAXN], sh, ush;
  for(int i = 0; i < MAXN; ++i) cin >> mi[i];
  for(int i = 0; i < MAXN; ++i) cin >> wi[i];
  cin >> sh >> ush;
  int finalScore = 0;
  for(int i = 0; i < MAXN; ++i) {
    finalScore += max(0.3 * (double)value[i], (1.0 - ((mi[i] * 1.0) / (250 * 1.0))) * (value[i] * 1.0) - (50 * wi[i]));
  }
  finalScore += ((100 * sh) - (50 * ush));
  cout << finalScore << endl;
}
