class Solution {
public:
    int find(vector<int>&parent, int u) {
        if(parent[u] == -1) return u;
        return parent[u] = find(parent, parent[u]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>parent(n + 1, -1);
        for(int i=0; i<n; i++) {
            int u = find(parent, edges[i][0]);
            int v = find(parent, edges[i][1]);
            if(u == v) return edges[i];
            parent[u] = v;
        }
        return {};
    }
};