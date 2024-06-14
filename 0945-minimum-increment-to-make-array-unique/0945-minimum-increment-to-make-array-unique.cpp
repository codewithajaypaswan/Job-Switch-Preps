class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i=1; i<n; i++) {
            if(nums[i-1] >= nums[i]) {
                int need = nums[i-1] - nums[i] + 1;
                ans += need;
                nums[i] += need;
            }
        }
        return ans;
    }
};