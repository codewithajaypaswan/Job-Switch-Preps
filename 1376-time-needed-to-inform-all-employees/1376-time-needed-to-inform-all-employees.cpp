class Solution {
public:
    int ans = 0;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int>adj[n];
        for(int i=0; i<n; i++) {
            if(headID == i) continue;
            adj[manager[i]].push_back(i);
        }
        dfs(adj, headID, informTime, 0);
        return ans;
    }
    void dfs(vector<int>adj[], int cur, vector<int>&informTime, int sum) {
        sum += informTime[cur];
        ans = max(ans, sum);
        for(int child:adj[cur]) {
            dfs(adj, child, informTime, sum);
        }
    }
};