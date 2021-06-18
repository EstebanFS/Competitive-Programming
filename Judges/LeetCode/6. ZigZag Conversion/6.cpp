class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char> > zig(numRows);
        int cl = 0;
        string ans;
        while(cl < s.size()) {
            for(int i = 0; i < numRows && cl < s.size(); ++i) {
                zig[i].push_back(s[cl]);
                cl++;
            }
            for(int i = 1; i < numRows - 1 && cl < s.size(); ++i) {
                zig[numRows - i - 1].push_back(s[cl]);
                cl++;
            }
        }
        for(int i = 0; i < numRows; ++i) {
            for(int j = 0; j < zig[i].size(); ++j) ans += zig[i][j];
        }
        return ans;
    }
};
