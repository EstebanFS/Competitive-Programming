#include <bits/stdc++.h>

using namespace std;


#define D(x) cout << #x << " " << x << endl
#define pii pair<int, int>


template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

void solve(string &s) {
  vector<pii> letters;
  vector<int> ans;
  int cost = 0, lastLetter;
  for(int i = 1; i < s.size() - 1; ++i) {
    if(s[i] >= min(s[0], s.back()) && s[i] <= max(s[0], s.back())) {
      letters.push_back(pii(s[i], i + 1));
    }
  }
  if(s[0] > s.back()) sort(letters.rbegin(), letters.rend());
  else sort(letters.begin(), letters.end());

  lastLetter = s[0];
  ans.push_back(1);
  for(int i = 0; i < letters.size(); ++i) {
    cost += abs(lastLetter - letters[i].first);
    ans.push_back(letters[i].second);
    lastLetter = letters[i].first;
  }
  cost += abs(lastLetter - s.back());
  ans.push_back(s.size());
  cout << cost << " " << ans.size() << endl;
  for(int i = 0; i < ans.size(); ++i) {
    if(i == 0) cout << ans[i];
    else cout << " " << ans[i];
  }
  cout << endl;
}

int main() {
  int t, n;
  string s;
  cin >> t;
  while(t--) {
    cin >> s;
    solve(s);
  }
  return 0;
}
