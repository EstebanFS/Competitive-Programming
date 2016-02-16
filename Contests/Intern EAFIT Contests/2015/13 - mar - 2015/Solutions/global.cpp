//Santiago Vanegas Gil.
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stack>

using namespace std;

int t;

int
main() {
  cin >> t;
  getchar();
  while (t--) {
    char c;
    stack <int> s;
    int i = 0, ans = 0;
    while ((c = getchar()) && c != '\n') {
      switch (c) {
        case '/':
          if (s.size() > 0) {
            ans += (i - s.top());
            s.pop();
          }
          break;
        case '\\':
          s.push(i);
          break;
      }
      i++;
    }
    cout << ans << endl;
  }
  return 0;
}
