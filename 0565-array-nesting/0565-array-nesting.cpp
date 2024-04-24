class Solution {
public:
    int dfs(vector<int>&nums, int cur) {
        if(nums[cur] == -1) return 0;
        int next = nums[cur];
        nums[cur] = -1;
        return 1 + dfs(nums, next);
    }
    int arrayNesting(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] != -1) {
                ans = max(ans, dfs(nums, i));
            }
        }
        return ans;
    }
};