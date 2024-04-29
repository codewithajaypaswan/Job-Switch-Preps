class Solution {
public:
    vector<int>ans;
    bool cycle(vector<int>adj[], vector<int>&vis, int u) {
        if(vis[u] == 2) return true;
        if(vis[u] == 1) return false;
        vis[u] = 2;
        for(int x:adj[u]) {
            if(cycle(adj, vis, x)) return true;
        }
        vis[u] = 1;
        return false;
    }

    void dfs(vector<int>adj[], vector<int>&vis, int cur) {
        if(vis[cur] == 1) return;
        vis[cur] = 1;
        for(int child:adj[cur]) {
            dfs(adj, vis, child);
        }
        ans.push_back(cur);
    }
        
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int>adj[n];
        for(auto e:pre) {
            adj[e[0]].push_back(e[1]);
        }
        vector<int>vis(n, 0);
        for(int i=0; i<n; i++) {
            if(vis[i] == 0) {
                if(cycle(adj, vis, i)) return {};
            }
        }
        vector<int>visited(n, 0);
        for(int i=0; i<n; i++) {
            if(visited[i] == 0) {
                dfs(adj, visited, i);
            }
        }
        return ans;
    }
};