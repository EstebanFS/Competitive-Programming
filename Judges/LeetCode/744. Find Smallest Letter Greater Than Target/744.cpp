class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int hight = n - 1;
        int low = 0;
        while(low <= hight) {
            int mid = (low + hight) / 2;
            if(letters[mid] <= target) low = mid + 1;
            else hight = mid - 1;
        }
        return letters[low % n];
    }
};
