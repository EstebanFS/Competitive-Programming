class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
          map <int, int> diffSum;
          vector <int> ans;
          for(int i = 0; i < nums.size(); ++i) {
                  if(diffSum.count(nums[i])) {
                          ans.push_back(diffSum[nums[i]]);
                          ans.push_back(i);
                          break;
                  } else {
                          diffSum[target - nums[i]] = i;
                  }
          }
          return ans;
  }
}
