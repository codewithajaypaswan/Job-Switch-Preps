class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int>adj[n];
        for(int i=0; i<n; i++) {
            if(headID == i) continue;
            adj[manager[i]].push_back(i);
        }
        queue<pair<int, int>>q;
        q.push({headID, 0});
        int ans = 0;
        while(!q.empty()) {
            auto[cur, time] = q.front(); q.pop();
            ans = max(ans, time);
            for(auto it:adj[cur]) {
                q.push({it, time + informTime[cur]});
            }
        }
        return ans;
    }
};