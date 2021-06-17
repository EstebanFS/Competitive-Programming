class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), ansj = 0, ansi = 0;
        string ans;
        bool dp[n + 5][n + 5];
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) dp[i][j] = false;
        }
        for(int i = 0; i < n; ++i) dp[i][i] = true;
        for(int i = 0; i < n - 1; ++i) {
            if(s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                ansi = i;
                ansj = i + 1;
            }
        }
        for(int k = 3; k <= n; ++k) {
            for(int i = 0; i <= n - k; ++i) {
                int j = i + k - 1;
                if(dp[i + 1][j - 1] == true && s[i] == s[j]) {
                    dp[i][j] = true;
                    ansi = i;
                    ansj = j;
                }
            }
        }
        for(int i = ansi; i <= ansj; ++i) ans += s[i];
        return ans;
    }
};
