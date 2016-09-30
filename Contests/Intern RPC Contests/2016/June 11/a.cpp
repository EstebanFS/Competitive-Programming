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
#define MAXN 10
#define pdi pair <double, int>
double wratio = 1.0 / 3.0, lratio = 1.0 / 2.0;

int main(){
  int t;
  cin >> t;
  while(t--) {
    for(int i = 0; i < 5; ++i) {
      string name; double k, d;
      cin >> name >> k >> d;
      if(k / d < wratio) printf("%s plz uninstall\n", name.c_str());
    }
    string lossers[MAXN];
    vector <double> ratios;
    double k, d;
    cin >> lossers[0] >> k >> d;
    double minRatio = k / d;
    ratios.push_back(k / d);
    for(int i = 1; i < 5; ++i) {
      cin >> lossers[i] >> k >> d;
      minRatio = min(minRatio, k / d);
      ratios.push_back(k / d);
    }
    for(int i = 0; i < 5; ++i) {
      double ratio = ratios[i];
      if(ratio < lratio || ratio == minRatio) printf("%s plz uninstall\n", lossers[i].c_str());
    }
  }
	return 0;
}
