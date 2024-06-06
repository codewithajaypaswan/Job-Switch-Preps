class Solution {
public:
    #define ll long long
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        ll mx = 1, mn = 1, ans = INT_MIN;
        for(int x:nums) {
            if(x < 0) swap(mx, mn);
            if(mx*x > INT_MAX || mn * x < INT_MIN) continue;
            mx = max((ll) x, mx * x);
            mn = min((ll) x, mn * x);
            ans = max(ans, mx);
        }
        return ans;
    }
};