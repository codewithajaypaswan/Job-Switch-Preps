class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        if(k == 0) return 0;
        for(int high = 0, low = 0, prod = 1; high < nums.size(); high++) {
            prod *= nums[high];
            while(prod >= k && low <= high) {
                prod/=nums[low++];
            }
            ans += high - low + 1;
        }
        return ans;
    }
};