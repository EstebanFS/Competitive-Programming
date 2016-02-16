#include <bits/stdc++.h>

using namespace std;

int n;

int
main() {
  while (cin >> n) {
    int ans = 0;
    for (int k = 0; k <= 2; ++k) {
      int curAns = n;
      int empty = n + k;
      while (empty / 3 > 0) {
        curAns += empty / 3;
        empty = (empty / 3) + (empty % 3);
      }
      if (empty >= k) ans = max(ans, curAns);
    }
    cout << ans << endl;
  }
  return 0;
}

