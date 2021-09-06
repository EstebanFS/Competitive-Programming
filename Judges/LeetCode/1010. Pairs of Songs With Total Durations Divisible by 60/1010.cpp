#define MAXM 70
#define D(x) cout << #x << " " << x << endl

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> resultModule(MAXM, 0);
        int ans = 0;
        for(int i = 0; i < time.size(); ++i) {
            int result = time[i] % 60;
            int diff = result == 0 ? 0 : 60 - result;
            ans += resultModule[diff];
            resultModule[result]++;
        }
        return ans;
    }
};
