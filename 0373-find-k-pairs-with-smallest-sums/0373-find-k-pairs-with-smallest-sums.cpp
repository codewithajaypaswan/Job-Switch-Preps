class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size(), m = b.size();
        vector<vector<int>>ans;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        for(int i=0; i<n; i++) {
            pq.push({a[i] + b[0], i, 0});
        }
        while(!pq.empty() && k-- > 0) {
            auto it = pq.top(); pq.pop();
            int i = it[1], j = it[2];
            ans.push_back({a[i], b[j]});
            if(j+1 < m) {
                pq.push({a[i] + b[j+1], i, j+1});
            }
        }
        return ans;
    }
};