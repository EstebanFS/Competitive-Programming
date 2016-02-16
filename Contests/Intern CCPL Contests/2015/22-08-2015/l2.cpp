#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define psi pair<string, int>

int t, n, ans;
string needle, haystack;
vector <int> border;

vector <int>
build_border(const string &needle) {
  vector <int> bord(n);
  bord[0] = 0;

  for (int i = 1; i < n; ++i) {
    bord[i] = bord[i - 1];
    while (bord[i] > 0 && needle[i] != needle[bord[i]])
      bord[i] = bord[bord[i] - 1];
    if (needle[i] == needle[bord[i]]) bord[i]++;
  }
  return bord;
}

void
kmp() {
  printf("needle: %s y hay: %s\n", needle.c_str(), haystack.c_str());
  int seen = 0;
  for (int i = 0; i < 2 * n; ++i) {
    while (seen > 0 && haystack[i] != needle[seen])
      seen = border[seen - 1];
    printf("hay[%d] = %c == ned[%d] = %c\n", i, haystack[i], seen, needle[seen]);
    if (haystack[i] == needle[seen]) seen++;
    else if (haystack[i] < needle[seen]) {
      puts("hola");
      needle = haystack.substr(i - seen, n);
      ans = i - seen + 1;
    }
    if (seen == n) { // Iguales entre [i - n + 1, i]
      printf("Occ %d, %d\n", i - n + 1, i);
    }
  }
}

int
main() {
  cin >> t;
  cin.ignore();
  while (t--) {
    ans = 1;
    getline(cin, needle);
    n = needle.size();
    border = build_border(needle);
    haystack = needle + needle;
    kmp();
    cout << ans << endl;
  }
  return 0;
}
