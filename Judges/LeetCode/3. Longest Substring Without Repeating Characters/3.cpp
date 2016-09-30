class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lastPos[300], maxi = 0, currPoint = 0;
        for(int i = 0; i < 300; ++i) lastPos[i] = -1;
        for(int i = 0; i < s.size(); ++i) {
            int currChar = s[i];
            if(currPoint <= lastPos[currChar]) {
                currPoint = lastPos[currChar] + 1;
            }
            int subSize = i - currPoint + 1;
            maxi = max(maxi, subSize);
            //printf("currChar: %c, maxi: %d, currPoint: %d, lastPos: %d\n", currChar, maxi, currPoint, lastPos[currChar]);
            lastPos[currChar] = i;
        }
        return maxi;
    }
};
