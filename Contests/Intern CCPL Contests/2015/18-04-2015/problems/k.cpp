#include <bits/stdc++.h>

using namespace std;

int t;
string line;


int
main() {
  cin >> t;
  while (t--) {
    cin >> line;
    int acum = 0;
    int ans = 0;
    for (int i = 0; i < line.size(); ++i) {
      if (line[i] == 'O') {
        acum++;
      }
      else {
        acum = 0; 
      }
      ans += acum;
    }
    cout << ans << endl;
  }
  return 0;
}

