class Solution {
    public int minSwaps(int[] nums) {
        int n = nums.length, cnt1 = 0, ans = Integer.MAX_VALUE;
        for(int i=0; i<nums.length; i++) {
            if(nums[i] == 1) cnt1++;
        }
        for(int i=0, j=0, oneInWindow=0; i < n; i++) {
            // cnt one in the window
            while((j - i) < cnt1) {
                oneInWindow += nums[j%n];
                j++;
            }
            ans = Math.min(ans, cnt1 - oneInWindow);
            oneInWindow -= nums[i];
        }
        return ans;
    }
}