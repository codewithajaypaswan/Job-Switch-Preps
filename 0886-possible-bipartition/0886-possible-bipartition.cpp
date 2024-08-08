class Solution {
public:
    bool dfs(vector<int>adj[], int cur, vector<int>&color, int curColor, int parent) {
        if(color[cur] != 0) return color[cur] == curColor;
        color[cur] = curColor;
        for(int x:adj[cur]) {
            if(x == parent) continue;
            if(!dfs(adj, x, color, -curColor, cur)) return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>adj[n+1];
        for(auto e:dislikes) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>color(n+1, 0);
        for(int i=1; i<=n; i++) {
            if(color[i] == 0) {
                if(!dfs(adj, i, color, 1, -1)) return false;
            }
        }
        return true;
    }
};