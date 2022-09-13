#include <bits/stdc++.h>

using namespace std;


#define D(x) cout << #x << " " << x << endl
#define vi vector<int>
#define pii pair<int, int>


template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int main() {
  int t, n;
  cin >> t;
  while(t--) {
    cin >> n;
    vi spend(n), budget(n), diff(n);
    int ans = 0;
    for(int i = 0; i < n; ++i) cin >> spend[i];
    for(int i = 0; i < n; ++i) cin >> budget[i];
    for(int i = 0; i < n; ++i) diff[i] = budget[i] - spend[i];
    sort(diff.begin(), diff.end());
    int left = 0, right = n - 1;
    while(left < right) {
      int sum = diff[left] + diff[right];
      if(sum >= 0) {
        ans++;
        left++;
        right--;
      } else {
        left++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
