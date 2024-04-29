class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto e:edges) {
            adj[e[0]].push_back(e[1]);
        }
        vector<int>vis(n, 0);
        for(int i=0; i<n; i++) {
            if(vis[i] == 0) {
                if(dfs(adj, i, vis)) return false;
            }
        }
        return true;
    }
    
    bool dfs(vector<int>adj[], int cur, vector<int>&vis) {
        if(vis[cur] == 2) return true;
        if(vis[cur] == 1) return false;
        vis[cur] = 2;
        for(int child:adj[cur]) {
            if(dfs(adj, child, vis)) return true;
        }
        vis[cur] = 1;
        return false;
    }
};