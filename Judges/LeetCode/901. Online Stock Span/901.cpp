#define D(x) cout << #x << " " << x << endl
#define pii pair<int, int>

class StockSpanner {
public:
    stack<pii> summary;
    
    int insertElement(int value) {
        int spans = 1;
        while(!summary.empty() && summary.top().first <= value) {
            pii curr = summary.top();
            spans += curr.second;
            summary.pop();
        }
        summary.push(pii(value, spans));
        return spans;
    }
    
    StockSpanner() {
        summary = stack<pii>();
    }
    
    int next(int price) {
        return insertElement(price);
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
