class Solution {
public:
    int solve(vector<int>adj[], int node, int &farthest, int sz) {
        vector<int>dist(sz + 1, -1);
        helper(adj, node, farthest, dist, 0);
        return dist[farthest];
    }
    void helper(vector<int>adj[], int node, int &farthest, vector<int>&dist, int distance) {
        dist[node] = distance;
        if(distance > dist[farthest]) {
            farthest = node;
        }
        for(int child:adj[node]) {
            if(dist[child] == -1) {
                helper(adj, child, farthest, dist, distance + 1);
            }
        }
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        const int n = edges1.size(), m = edges2.size();
        vector<int>adj1[n+1];
        vector<int>adj2[m+1];
        for(auto e:edges1) {
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        for(auto e:edges2) {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }
        int farthest1 = 0;
        solve(adj1, 0, farthest1, n);
        int dia1 = solve(adj1, farthest1, farthest1, n);
        
        int farthest2 = 0;
        solve(adj2, 0, farthest2, m);
        // cout<<farthest1<<" "<<farthest2<<endl;
        int dia2 = solve(adj2, farthest2, farthest2, m);
        // cout<<" "<<dia1<< " "<<dia2<<endl;
        int ans = max({dia1, dia2, (dia1 + 1)/2 + (dia2 + 1)/2 + 1});
        return ans;
    }
};