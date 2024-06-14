class Solution {
    public int minIncrementForUnique(int[] nums) {
        Arrays.sort(nums);
        int ans = 0, n = nums.length;
        for(int i=1; i<n; i++) {
            if(nums[i-1] >= nums[i]) {
                int need = nums[i-1] - nums[i] + 1;
                ans += need;
                nums[i] += need;
            }
        }
        return ans;
    }
}