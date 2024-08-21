class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<int>ans;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        priority_queue<pair<double, pair<int,int>>, vector<pair<double, pair<int,int>>>, greater<pair<double, pair<int,int>>>>pq;
        for(int i=0; i<n; i++) {
            pq.push({(double) arr[0]/arr[i], {0, i}});
        }
        while(k-- > 1 && !pq.empty()) {
            auto it = pq.top(); pq.pop();
            int x = it.second.first, y = it.second.second;
            if(x + 1 < n) {
                pq.push({(double) arr[x+1]/arr[y], {x+1, y}});
            }
        }
        if(pq.empty()) return {-1, -1};
        auto it = pq.top();
        return {arr[it.second.first], arr[it.second.second]};
    }
};