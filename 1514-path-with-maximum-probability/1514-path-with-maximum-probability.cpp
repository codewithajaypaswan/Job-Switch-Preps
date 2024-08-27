class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int, double>>adj[n];
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<int>vis(n, 0);
        priority_queue<pair<double, int>>pq;
        pq.push({1.0, start_node});
        vector<double>ans(n, 0.0);
        ans[start_node] = 1.0;
        while(!pq.empty()) {
            auto it = pq.top(); pq.pop();
            double prob = it.first;
            int u = it.second;
            if(u == end_node) return prob;
            vis[u] = 1;
            for(auto child:adj[u]) {
                int v = child.first;
                double nextProb = child.second;
                if(vis[v] == 0 && ans[v] < prob * nextProb) {
                    ans[v] = prob * nextProb;
                    pq.push({prob * nextProb, v});
                }
            }
        }
        return ans[end_node];
    }
};