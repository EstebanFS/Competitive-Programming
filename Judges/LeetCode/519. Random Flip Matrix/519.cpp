#define D(x) cout << #x << " " << x << endl 

class Solution {
public:
    unordered_map<int, int> m;
    int total, _n, _m;
    Solution(int m, int n) {
        _m = m;
        _n = n;
        total = m * n;
    }
    
    vector<int> flip() {
        int next = rand() % total--;
        int index = m.count(next) ? m[next] : next;
        m[next] = m.count(total) ? m[total] : total;
        return {index / _n, index % _n};
    }
    
    void reset() {
        total = _n * _m;
        m.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
