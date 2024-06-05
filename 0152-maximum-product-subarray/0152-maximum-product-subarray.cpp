class Solution {
public:
    #define ll long long
    int maxProduct(vector<int>& nums) {
        ll mx = 1, mn = 1, ans = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] < 0) swap(mx, mn);
            if(mx*nums[i] >= INT_MAX || mn*nums[i] <= INT_MIN) continue;
            mx = max((ll)nums[i], mx * nums[i]);
            mn = min((ll)nums[i], mn * nums[i]);
            ans = max(ans, mx);
        }
        return ans;
    }
};