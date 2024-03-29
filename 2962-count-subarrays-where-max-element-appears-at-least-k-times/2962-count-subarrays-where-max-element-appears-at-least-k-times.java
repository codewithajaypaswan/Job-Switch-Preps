class Solution {
    public long countSubarrays(int[] nums, int k) {
        long ans = 0, n = nums.length;
        int mx = Arrays.stream(nums).max().getAsInt();
        for(int high = 0, low = 0, count = 0; high < n; high++) {
            if(nums[high] == mx) count++;
            while(count >= k) {
                if(nums[low] == mx) count--;
                ans += (n - high);
                low++;
            }
        }
        return ans;
    }
}