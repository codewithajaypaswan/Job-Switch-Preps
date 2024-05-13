class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        int ans = 0, n = nums.length, sum = 0;
        Map<Integer, Integer>mp = new HashMap<>();
        mp.put(sum, 1);
        for(int i=0; i<n; i++) {
            sum += nums[i];
            if(mp.containsKey(sum - goal)) {
                ans += mp.get(sum - goal);
            }
            mp.put(sum, mp.getOrDefault(sum, 0) + 1);
        }
        return ans;
    }
}