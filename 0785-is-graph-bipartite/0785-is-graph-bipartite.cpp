class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int cur, int color, vector<int>&vis) {
        if(vis[cur] != 0) return vis[cur] == color;
        vis[cur] = color;
        for(auto child:graph[cur]) {
            if(!dfs(graph, child, -color, vis)) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n, 0);
        for(int i=0; i<n; i++) {
            if(vis[i] == 0) {
                if(!dfs(graph, i, 1, vis)) return false;
            }
        }
        return true;
    }
};