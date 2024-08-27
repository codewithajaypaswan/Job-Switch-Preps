class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int, double>>adj[n];
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        priority_queue<pair<double, int>>pq;
        vector<int>vis(n, 0);
        vector<double>prob(n, 0.0);
        prob[start_node] = 1.0;
        pq.push({1.0, start_node});
        while(!pq.empty()) {
            auto[cur_prob, u] = pq.top(); pq.pop();
            if(u == end_node) return cur_prob;
            vis[u] = 1;
            for(auto[v, next_prob]:adj[u]) {
                if(vis[v] == 0 && prob[v] < cur_prob * next_prob) {
                    prob[v] = cur_prob * next_prob;
                    pq.push({prob[v], v});
                }
            }
        }
        return prob[end_node];
    }
};