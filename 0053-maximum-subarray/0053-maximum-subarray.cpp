class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSoFar = nums[0], ans = nums[0];
        for(int i=1; i<n; i++) {
            maxSoFar = max(nums[i], maxSoFar + nums[i]);
            ans = max(ans, maxSoFar);
        }
        return ans;
    }
};