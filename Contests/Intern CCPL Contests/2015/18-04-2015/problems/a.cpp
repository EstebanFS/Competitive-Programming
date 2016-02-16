#include <bits/stdc++.h>

using namespace std;

template <class T> string toStr(const T &x) {
  stringstream s; s << x; return s.str(); 
}
int
main() {
  string s;
  string origS;
  while (cin >> s && s != "0") {
    origS = s;
    int acum;
    int degree = 0;
    if (s == "9") degree = 1;
    bool mult = true;
    while (s.size() > 1 && mult) {
      acum = 0;
      for (int  i = 0; i < s.size(); ++i) {
        acum += (s[i] - '0');
      }
      if (acum % 9 != 0) mult = false;
      degree++;
      s = toStr(acum);
    }
    if (mult) cout << origS << " is a multiple of 9 and has 9-degree " << degree << "." << endl;
    else cout << origS << " is not a multiple of 9." << endl;
  }
  return 0;
}

