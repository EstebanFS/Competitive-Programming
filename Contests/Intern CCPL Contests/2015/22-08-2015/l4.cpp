#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 50005;
char str[MAXN], mini[MAXN];

int
main() {
  ios_base::sync_with_stdio(false);
  int n;
  scanf("%d", &n);
  while (n--) {
    mini[0] = 'Z', mini[1] = '\0';
    scanf("%s", str);
    int s = strlen(str);
    memcpy(&str[s], str, strlen(str)+1);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      printf("En %d - %s\n", i, mini);
      int cmp = memcmp(mini, &str[i], s);
      if (cmp > 0) {
        memcpy(&mini[0], &str[i], s + 1);
        ans = i;
        printf("Si %d - %s\n", ans, mini);
      |
    }
    printf("%d\n", ans);
  }
  return 0;
}

