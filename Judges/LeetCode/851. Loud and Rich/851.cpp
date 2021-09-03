#define MAXN 505
#define pii pair<int, int>
#define D(x) cout << #x << " " << x << endl

class Solution {
public:
    vector<int> g[MAXN];
    
    pii dfs(int u, vector<int> &quiet, vector<bool> &visited, vector<pii> &memo) {
        visited[u] = true;
        pii leastQuiet = pii(u, quiet[u]);
        for(int i = 0; i < g[u].size(); ++i) {
            int next = g[u][i];
            if(!visited[next]) {
                pii tmp;
                if(memo[next].first == -1) tmp = dfs(next, quiet, visited, memo);
                else tmp = memo[next];
                if(tmp.second < leastQuiet.second) leastQuiet = tmp;
            }
        }
        memo[u] = leastQuiet;
        return leastQuiet;
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> ans(n, -1);
        vector<pii> memo(n, pii(-1, -1));
        for(int i = 0; i < richer.size(); ++i) {
            int x = richer[i][0], y = richer[i][1];
            g[y].push_back(x);
        }
        for(int i = 0; i < n; ++i) {
            if(ans[i] != -1) continue;
            vector<bool> visited(n, false);
            dfs(i, quiet, visited, memo);
        }
        for(int i = 0; i < n; ++i) ans[i] = memo[i].first;
        return ans;
    }
};
