class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n+1, 0);
        for(int i=0; i<n; i++) {
            if(vis[i] == 0) {
                vis[i] = 1;
                queue<int>q;
                q.push(i);
                while(!q.empty()) {
                    int cur = q.front(); q.pop();
                    for(int child:graph[cur]) {
                        if(vis[child] == 0) {
                            vis[child] = -vis[cur];
                            q.push(child);
                        }
                        else if(vis[child] != -vis[cur]) return false;
                    }
                }
            }
        }
        return true;
    }
};