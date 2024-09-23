class Solution {
public:
    double dist(vector<int>p) {
        return (double) sqrt((p[0] * p[0]) + (p[1] * p[1]));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, pair<int, int>>>pq;
        for(auto p:points) {
            double d = dist(p);
            pq.push({d, {p[0], p[1]}});
            if(pq.size() > k) pq.pop();
        }
        vector<vector<int>>ans;
        while(pq.size() > 0) {
            auto it = pq.top().second;
            pq.pop();
            ans.push_back({it.first, it.second});
        }
        return ans;
    }
};