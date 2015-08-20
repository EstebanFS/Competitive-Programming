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
  int n, m;
  cin >> n >> m;
  int votes[n];
  map  <int, vector<int> > cities;
  int maxi = 0;
  for(int i = 0; i < n; ++i) votes[i] = 0;
  for(int i = 0; i < m; ++i) {
    maxi = 0;
    cities.clear();
    for(int j = 0; j < n; ++j) {
      int vote;
      cin >> vote;
      cities[vote].push_back(j);
      maxi = max(maxi, vote);
    }
    int winner = cities[maxi][0];
    votes[winner]++;
  }
  int winner = 0;
  int score = votes[0];
  for(int i = 1; i < n; ++i) {
    if(score < votes[i]) {
      score = votes[i];
      winner = i;
    }
  }
  cout << winner + 1 << endl;
  return 0;
}
