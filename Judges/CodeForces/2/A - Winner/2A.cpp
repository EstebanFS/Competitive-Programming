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
#define pii pair<int, int>
#define psi pair<string, int>

int main() {
  int n;
  cin >> n;
  map <string, pii> g;
  vector <psi> players;
  for(int i = 0; i < n; ++i) {
    string name;
    int score;
    cin >> name >> score;
    g[name] = pii(g[name].first + score, i);
    players.push_back(psi(name, score));
  }
  map <string, pii>::iterator it;
  map <string, bool> winners;
  map <string, int> firstWinner;
  int maxi = 0;
  string winner;
  for(it = g.begin(); it != g.end(); ++it) maxi = max(it -> second.first, maxi);
  for(it = g.begin(); it != g.end(); ++it) {
    int score = it -> second.first;
    string name = it -> first;
    if(score == maxi) winners[name] = true;
  }
  for(int i = 0; i < players.size(); ++i) {
    string name = players[i].first;
    firstWinner[name] += players[i].second;
    if(winners[name] && firstWinner[name] >= maxi) {
      winner = name;
      break;
    }
  }
  cout << winner << endl;
  return 0;
}
