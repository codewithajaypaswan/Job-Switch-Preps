class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = INT_MAX;
        int i = 0, j = n-4;
        while(j < n && j >= 0) {
            ans = min(ans, nums[j++] - nums[i++]);
        }
        return ans == INT_MAX ? 0 : ans;
    }
};