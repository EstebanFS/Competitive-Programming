class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map <int, int> f;
        int ans;
        for(int i = 0; i < nums.size(); ++i) f[nums[i]]++;
        for(int i = 0; i < nums.size(); ++i) {
            if(f[nums[i]] == 1) ans = nums[i];
        }
        return ans;
    }
};
