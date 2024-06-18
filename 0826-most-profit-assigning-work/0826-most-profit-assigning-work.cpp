class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int ans = 0, n = profit.size();
        vector<pair<int,int>>vp;
        for(int i=0; i<n; i++) {
            vp.push_back({difficulty[i], profit[i]});
        }
        sort(vp.begin(), vp.end());
        sort(worker.begin(), worker.end());
        int ind = 0, mx = 0;
        for(int i=0; i<worker.size(); i++) {
            while(ind < n && worker[i] >= vp[ind].first) {
                mx = max(mx, vp[ind].second);
                ind++;
            }
            ans += mx;
        }
        return ans;
    }
};