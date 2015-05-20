// Santiago Vanegas Gil
#include <iostream>
 
using namespace std;
 
int
main() {
    int n, ans;
    while (cin >> n && n) {
      ans = 0;
      for (int i = 0; i < n; ++i) {
        int xi; cin >> xi;
        ans += (xi <= 1000);
      }
      cout << ans << endl;
    }
    return 0;
}
