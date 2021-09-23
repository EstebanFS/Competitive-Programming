#define D(x) cout << #x << " " << x << endl

class Solution {
public:
    bool isValid(int maxDays, int capacity, vector<int> &weights) {
        int tmp = 0, usedDays = 0;
        for(int i = 0; i < weights.size(); ++i) {
            tmp += weights[i];
            if(weights[i] > capacity) return false;
            if(tmp > capacity) {
                tmp = 0;
                i--;
                usedDays++;
            }
        }
        usedDays++;
        return usedDays <= maxDays;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0, high = 0;
        for(int i = 0; i < weights.size(); ++i) high += weights[i];
        while(low <= high) {
            int mid = (low + high) / 2;
            D(low); D(high); D(mid);
            if(isValid(days, mid, weights)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};
