class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int>adj[n+1];
        for(auto e:edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>freq(n+1, 0), dist1(n+1, INT_MAX), dist2(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, 1});
        dist1[1] = 0;
        while(!pq.empty()) {
            auto[timeTaken, u] = pq.top(); pq.pop();
            freq[u]++;
            if(u == n && freq[u] == 2) return timeTaken;
            // handle signal
            if((timeTaken/change)%2 == 1) {
                timeTaken = change * (timeTaken/change + 1) + time;
            }
            else {
                timeTaken = timeTaken + time;
            }
            for(auto v:adj[u]) {
                if(freq[v] == 2) continue;
                if(dist1[v] > timeTaken) {
                    dist2[v] = dist1[v];
                    dist1[v] = timeTaken;
                    pq.push({dist1[v], v});
                }
                else if(dist2[v] > timeTaken && dist1[v] != timeTaken) {
                    dist2[v] = timeTaken;
                    pq.push({dist2[v], v});
                }
            }
        }
        return 0;
    }
};