class Solution {
public:
    int dfs(vector<int>adj[], int cur, vector<int>&informTime) {
        int res = 0;
        for(int child:adj[cur]) {
            res = max(res, dfs(adj, child, informTime));
        }
        return res + informTime[cur];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int>adj[n];
        for(int i=0; i<n; i++) {
            if(headID == i) continue;
            adj[manager[i]].push_back(i);
        }
        return dfs(adj, headID, informTime);
    }
};