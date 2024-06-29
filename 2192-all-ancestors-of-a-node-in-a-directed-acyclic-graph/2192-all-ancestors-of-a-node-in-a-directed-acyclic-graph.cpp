class Solution {
public:
    void solve(int cur, vector<vector<int>>&adj, vector<vector<int>>&ans, int x, vector<int>&vis) {
        vis[cur] = true;
        for(int child:adj[cur]) {
            if(!vis[child]) {
                ans[child].push_back(x);
                solve(child, adj, ans, x, vis);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>ans(n), adj(n);
        for(auto e:edges) {
            adj[e[0]].push_back(e[1]);
        }
        for(int i=0; i<n; i++) {
            vector<int>vis(n, 0);
            solve(i, adj, ans, i, vis);
        }
        return ans;
    }
};