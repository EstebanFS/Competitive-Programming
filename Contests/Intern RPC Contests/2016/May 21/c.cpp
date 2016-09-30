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
#define MAXN 30

string solve(string x) {
  int f[MAXN], change[MAXN];
  string ans;
  int curr = 1;
  for(int i = 0; i < MAXN; ++i) change[i] = i;
  change[2] = 5;
  change[5] = 2;
  change[6] = 9;
  change[9] = 6;
  for(int i = 0; i < MAXN; ++i) f[i] = -1;
  for(int i = 0; i < x.size(); ++i) {
    int currChar = x[i] - 'a';
    if(f[currChar] == -1) {
      f[currChar] = curr;
      curr++;
    }
    ans += toStr(f[currChar]);
  }
  for(int i = 0; i < ans.size(); ++i) ans[i] = (change[ans[i] - '0'] + '0');
  return ans;
}


int main(){
	string x;
  while(cin >> x) cout << solve(x) << endl;
	return 0;
}
