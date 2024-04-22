class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>visited, deadlock(deadends.begin(), deadends.end());
        if(deadlock.find("0000") != deadlock.end()) return -1;
        queue<string>q;
        q.push("0000");
        visited.insert("0000");
        int ans = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                string cur = q.front(); q.pop();
                string down = cur, up = cur;
                if(target == cur) return ans;
                for(int i=0; i<4; i++) {
                    down[i] = down[i] == '0' ? '9' : down[i] - 1;
                    up[i] = up[i] == '9' ? '0' : up[i] + 1;
                    if(visited.find(up) == visited.end() && deadlock.find(up) == deadlock.end()) {
                        q.push(up);
                        visited.insert(up);
                    }
                    if(visited.find(down) == visited.end() && deadlock.find(down) == deadlock.end()) {
                        q.push(down);
                        visited.insert(down);
                    }
                    down[i] = up[i] = cur[i];
                }
            }
            ans++;
        }
        return -1;
    }
};