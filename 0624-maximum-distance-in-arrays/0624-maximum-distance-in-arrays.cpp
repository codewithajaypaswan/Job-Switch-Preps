class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int ans = INT_MIN, mn = 1e9, mx = -1e9;
        mn = arr[0][0], mx = arr[0][arr[0].size()-1];
        for(int i=1; i<arr.size(); i++) {
            int curMin = arr[i][0], curMax = arr[i][arr[i].size()-1];
            ans = max({ans, curMax - mn, mx - curMin});
            mn = min(curMin, mn);
            mx = max(curMax, mx);
        }
        return ans;
    }
};