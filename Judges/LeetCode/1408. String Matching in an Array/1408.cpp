#define ALPHA 28
#define D(x) cout << #x << " " << x << endl

class Solution {
public:
    static bool sortBySize(const string &a, const string &b) {
        return a.size() <= b.size();
    }
    
    bool isSubString(string &small, string &big) {
        return big.find(small) != string::npos;
    }
    
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(), words.end(), sortBySize);
        vector<string> ans;
        for(int i = 0; i < words.size(); ++i) {
            for(int j = i + 1; j < words.size(); ++j) {
                if(isSubString(words[i], words[j])) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
