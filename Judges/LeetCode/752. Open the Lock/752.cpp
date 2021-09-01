#define umsi unordered_map<string, int>
#define uss unordered_set<string>
#define SLOTS 4

class Solution {
public:
    char rotateUp(char x) {
        if(x == '9') return '0';
        return x + 1;
    }
    
    char rotateDown(char x) {
        if(x == '0') return '9';
        return x - 1;
    }
    
    umsi bfs(uss &deadends) {
        umsi d;
        string start = "0000";
        if(deadends.count(start)) return d;
        d[start];
        queue<string> q;
        q.push(start);
        while(!q.empty()) {
            string curr = q.front();
            q.pop();
            for(int i = 0; i < SLOTS; ++i) {
                string nextUp = curr, nextDown = curr;
                nextUp[i] = rotateUp(nextUp[i]);
                nextDown[i] = rotateDown(nextDown[i]);
                if(!deadends.count(nextUp) && !d.count(nextUp)) {
                    d[nextUp] = d[curr] + 1;
                    q.push(nextUp);
                }
                if(!deadends.count(nextDown) && !d.count(nextDown)) {
                    d[nextDown] = d[curr] + 1;
                    q.push(nextDown);
                }
            }
        }
        return d;
    }
    
    int openLock(vector<string>& deadends, string target) {
        uss setDeadEnds;
        for(int i = 0; i < deadends.size(); ++i) setDeadEnds.insert(deadends[i]);
        umsi dist = bfs(setDeadEnds);
        if(!dist.count(target)) return -1;
        return dist[target];
    }
};
