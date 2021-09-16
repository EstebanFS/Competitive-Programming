#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define all(x) x.begin(), x.end()
typedef long long ll;

void solve(int tc) {
    int N, M, A, B;
    cin >> N >> M >> A >> B;

    vector<vector<int>> city(N, vector<int>(M, 1));
    city[0][0] = A - M - N + 2;
    city[N - 1][0] = B - M - N + 2;
    bool possible = city[0][0] > 0 and city[N - 1][0] > 0;

    cout << "Case #" << tc << ": " << (possible ? "Possible" : "Impossible") << endl;
    if (possible) {
        for (auto row : city) {
            for (auto c : row) cout << c << " ";
            cout << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 0;
    if (!t) cin >> t;
    for (int tc = 1; tc <= t; tc++) solve(tc);
    return 0;
}
