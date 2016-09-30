class Solution {
public:
  int jump(vector<int>& nums) {
          int ans = 0;
          if(nums.size() <= 1) return 0;
          if(nums[0] >= nums.size() - 1) return 1;
          queue <int> q;
          q.push(0);
          while(!q.empty()) {
                  int curr = q.front();
                  int maxIteration = curr + nums[curr];
                  int maxi = 0, next = 0;
                  ans++;
                  q.pop();
                  for(int i = curr + 1; i <= maxIteration; ++i) {
                          if(maxi < i + nums[i]) {
                                  maxi = i + nums[i];
                                  next = i;
                          }
                          if(i + nums[i] >= nums.size() - 1) return ans + 1;
                  }
                  q.push(next);
          }
          return ans;
  }
};
