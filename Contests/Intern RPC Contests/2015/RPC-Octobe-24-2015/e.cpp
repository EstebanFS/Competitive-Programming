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

struct skill {
  int r1, r2, r3;
  skill(const int _r1, const int _r2, const int _r3) {
    r1 = _r1;
    r2 = _r2;
    r3 = _r3;
  }
};

#define D(x) cout << #x " is " << x << endl
#define diff pair<int, int>

bool cmp(skill a, skill b) {
  return a.r1 < b.r1;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<skill> skills;
    vector<diff> diffs;
    for(int i = 0; i < n; ++i) {
      int r1, r2, r3;
      cin >> r1 >> r2 >> r3;
      skills.push_back(skill(r1, r2, r3));
      diffs.push_back(diff(r1 + r2 + r3, i));
    }
    sort(diffs.begin(), diffs.end());
    int noList = 0;
    int index = diffs[0].second;
    skill best = skills[index];
    D(best.r1);D(best.r2);D(best.r3);
    for(int i = 0; i < skills.size(); ++i) {
      if(i == index) continue;
      skill curr = skills[i];
      if(curr.r1 > best.r1 && curr.r2 > best.r2 && curr.r3 > best.r3) {
        noList++;
        D(curr.r1); D(curr.r2); D(curr.r3);
      }
    }
    cout << n - noList << endl;
  }
  return 0;
}
