#define MAXN 205
#define pii pair<int, int>
#define D(x) cout << #x << " " << x << endl

class Solution {
public:
    static bool sortFunction(const pii a, const pii b) {
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }
    
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> f(MAXN, 0), ans;
        vector<pii> pairs;
        for(int i = 0; i < nums.size(); ++i) f[nums[i] + 100]++;
        for(int i = 0; i < MAXN; ++i) {
            if(f[i] != 0) pairs.push_back(pii(f[i], i - 100));
        }
        sort(pairs.begin(), pairs.end(), sortFunction);
        for(int i = 0; i < pairs.size(); ++i) {
            int times = pairs[i].first;
            int number = pairs[i].second;
            for(int j = 0; j < times; ++j) ans.push_back(number);
        }
        return ans;
    }
};
