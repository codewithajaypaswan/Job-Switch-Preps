class Solution {
    HashMap<Integer, Integer>mp;
    int solve(int[] nums, int k, int ind) {
        if(ind >= nums.length) return 1;
        int ans = solve(nums, k, ind+1);
        if(!mp.containsKey(nums[ind] - k) && !mp.containsKey(nums[ind] + k)) {
            mp.put(nums[ind], mp.getOrDefault(nums[ind], 0) + 1);
            ans += solve(nums, k, ind+1);
            mp.put(nums[ind], mp.get(nums[ind]) - 1);
            if(mp.get(nums[ind]) == 0) {
                mp.remove(nums[ind]);
            }
        }
        return ans;
    }
    public int beautifulSubsets(int[] nums, int k) {
        mp = new HashMap<>();
        return solve(nums, k, 0) - 1;
    }
}