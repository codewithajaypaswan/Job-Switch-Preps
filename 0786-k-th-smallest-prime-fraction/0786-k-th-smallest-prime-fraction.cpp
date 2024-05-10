class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>>pq;
        for(int i=0; i<arr.size(); i++) {
            pq.push({(double)1.0 * arr[0]/arr[i], {0, i}});
        }
        while(k-- > 1 && !pq.empty()) {
            auto it = pq.top(); pq.pop();
            double val = it.first;
            int x = it.second.first, y = it.second.second;
            if(x+1 < arr.size()) {
                pq.push({(double)arr[x+1]/arr[y], {x+1, y}});
            }
        }
        int x = pq.top().second.first, y = pq.top().second.second;
        return {arr[x], arr[y]};
    }
};