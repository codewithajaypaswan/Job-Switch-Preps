class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), cnt = 0;
        vector<int>adj[n];
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(isConnected[i][j]) {
                    adj[i].push_back(j);
                }
            }
        }
        vector<int>vis(n, 0);
        for(int i=0; i<n; i++) {
            if(vis[i] == 0) {
                dfs(adj, i, vis);
                cnt++;
            }
        }
        return cnt;
    }
    void dfs(vector<int>adj[], int cur, vector<int>&vis) {
        if(vis[cur]) return;
        vis[cur] = 1;
        for(int child:adj[cur]) {
            dfs(adj, child, vis);
        }
    }
};