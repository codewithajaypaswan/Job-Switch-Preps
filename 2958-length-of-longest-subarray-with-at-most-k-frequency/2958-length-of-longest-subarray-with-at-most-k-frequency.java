class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
        int n = nums.length, ans = 0;
        Map<Integer, Integer>mp = new HashMap<>();
        for(int high = 0, low = 0; high<n; high++) {
            mp.put(nums[high], mp.getOrDefault(nums[high], 0) + 1);
            while(mp.get(nums[high]) > k) {
                mp.put(nums[low], mp.getOrDefault(nums[low], 0) - 1);
                low++;
            }
            ans = Math.max(ans, high - low + 1);
        }
        return ans;
    }
}