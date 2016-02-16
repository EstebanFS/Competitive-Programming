#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define psi pair<string, int>

int
main() {
   int n;
   cin >> n;
   while(n--) {
      string word;
      cin >> word;
      int s = word.size();
      word += word;
      vector<psi> weak;
      for(int i = 0; i < s; ++i) {
        string curr;
        for(int j = i; j < i + s; ++j) curr += word[j];
        weak.push_back(psi(curr, i));
      }
      sort(weak.begin(), weak.end());
      cout << weak[0].second + 1 << endl;
   }
  return 0;
}
