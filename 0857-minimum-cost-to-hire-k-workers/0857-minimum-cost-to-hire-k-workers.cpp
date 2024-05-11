class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = wage.size();
        vector<pair<double, int>>vp;
        for(int i=0; i<n; i++) {
            vp.push_back({(double)wage[i]/quality[i], quality[i]});
        }
        sort(vp.begin(), vp.end());
        priority_queue<int>pq;
        int sum = 0;
        double minCost = INT_MAX;
        for(int i=0; i<n; i++) {
            auto[ratio, q] = vp[i];
            pq.push(q); sum += q;
            if(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if(pq.size() == k) {
                minCost = min(minCost, ratio * sum);
            }
        }
        return minCost;
    }
};