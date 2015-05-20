#include <bits/stdc++.h>

using namespace std;

int n;
vector <int> numbers;

int
main() {
  bool first = true;
  while (cin >> n && n) {
    if (!first) puts("");
    first = false;
    numbers.clear();
    for (int i = 0; i < n; ++i) {
      int num; cin >> num;
      numbers.push_back(num);
    }
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        for (int k = j + 1; k < n; ++k) {
          for (int l = k + 1; l < n; ++l) {
            for (int m = l + 1; m < n; ++m) {
              for (int o = m + 1; o < n; ++o) {
                printf("%d %d %d %d %d %d\n", numbers[i], numbers[j], numbers[k], numbers[l], numbers[m], numbers[o]);
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

