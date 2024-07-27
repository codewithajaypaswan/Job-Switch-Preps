class Solution {
public:
    unordered_set<int>safe, unsafe;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n), ans;
        for(int i=0; i<n; i++) {
            if(dfs(graph, vis, i)) ans.push_back(i);
        }
        return ans;
    }
    bool dfs(vector<vector<int>>&graph, vector<int>&vis, int cur) {
        if(safe.find(cur) != safe.end()) return true;
        if(unsafe.find(cur) != unsafe.end()) return false;
        if(vis[cur]) {
            unsafe.insert(cur);
            return false;
        }
        vis[cur] = 1;
        for(int x:graph[cur]) {
            if(!dfs(graph, vis, x)) {
                unsafe.insert(x);
                return false;
            }
        }
        safe.insert(cur);
        return true;
    }
};