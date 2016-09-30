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
#include <unordered_map>

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r;}

#define ll unsigned long long
#define D(x) cout << #x << " " << x << endl
#define MAXN 1050

string generate(int n) {
  string result;
  for(int i = 0; i < n; ++i) {
    int value = rand() % 2;
    if(value) result += '+';
    else result += '-';
  }
  return result;
}

int main(){
  int t, n;
  cin >> t >> n;
  cout << t << endl;
  for(int i = 0; i < t; ++i) cout << generate(n) << endl;
	return 0;
}
