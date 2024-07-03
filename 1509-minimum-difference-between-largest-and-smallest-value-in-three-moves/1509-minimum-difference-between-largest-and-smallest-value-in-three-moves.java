class Solution {
    public int minDifference(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length, ans = Integer.MAX_VALUE;
        int i = 0, j = n-4;
        while(j < n && j >= 0) {
            ans = Math.min(ans, nums[j++] - nums[i++]);
        }
        return ans == Integer.MAX_VALUE ? 0 : ans;
    }
}