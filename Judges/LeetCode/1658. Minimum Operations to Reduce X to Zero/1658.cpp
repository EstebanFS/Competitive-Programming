#define D(x) cout << #x << " " << x << endl
#define ll long long

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), i = 0, j = 0, maxWindow = -1, total = 0, window = 0, reminder;
        for(int i = 0; i < n; ++i) total += nums[i];
        reminder = total - x;
        for(int i = 0; i < n; ++i) {
            window += nums[i];
            while(window > reminder && j <= i) {
                window -= nums[j];
                j++;
            }
            if(window == reminder) maxWindow = max(maxWindow, i - j + 1);
        }
        return maxWindow == -1 ? -1 : n - maxWindow;
    }
};
