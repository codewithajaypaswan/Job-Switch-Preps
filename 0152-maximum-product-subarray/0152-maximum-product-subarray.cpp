class Solution {
public:
    #define ll long long
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<ll>minVal(n), maxVal(n);
        minVal[0] = maxVal[0] = nums[0];
        for(int i=1; i<n; i++) {
            if(minVal[i-1] * nums[i] < INT_MIN || maxVal[i-1] * nums[i] > INT_MAX) continue;
            maxVal[i] = max({(ll) nums[i], minVal[i-1] * nums[i], maxVal[i-1] * nums[i]});
            minVal[i] = min({(ll) nums[i], maxVal[i-1] * nums[i], minVal[i-1] * nums[i]});
        }
        ll ans = INT_MIN;
        for(int i=0; i<n; i++) {
            ans = max((ll)ans, maxVal[i]);
        }
        return ans;
    }
};