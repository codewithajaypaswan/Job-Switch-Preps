class Solution {
    public double minimumAverage(int[] nums) {
        Arrays.sort(nums);
        int i = 0, j = nums.length-1;
        double val = 0, ans = (double)Integer.MAX_VALUE;
        while(i < j) {
            val = (double)(nums[i] + nums[j])/2;
            ans = Math.min(val, ans);
            i++;
            j--;
        }
        return ans;
    }
}