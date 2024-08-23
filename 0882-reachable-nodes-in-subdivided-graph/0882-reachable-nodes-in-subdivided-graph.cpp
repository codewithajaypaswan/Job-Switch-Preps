class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<pair<int, int>>adj[n];
        for(auto e:edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        unordered_map<int, int>seen;
        priority_queue<pair<int, int>>pq;
        pq.push({maxMoves, 0});
        while(!pq.empty()) {
            auto it = pq.top(); pq.pop();
            int cur = it.second, moves = it.first;
            if(seen.find(cur) != seen.end()) continue;
            seen[cur] = moves;
            for(auto child:adj[cur]) {
                int movesLeft = moves - child.second - 1;
                if(movesLeft >= 0 && seen.find(child.first) == seen.end()) {
                    pq.push({movesLeft, child.first});
                }
            }
        }
        int res = seen.size();
        // count all the inbetween nodes
        for(auto e:edges) {
            int a = seen.find(e[0]) == seen.end() ? 0 : seen[e[0]];
            int b = seen.find(e[1]) == seen.end() ? 0 : seen[e[1]];
            res += min(a+b, e[2]);
        }
        return res;
    }
};