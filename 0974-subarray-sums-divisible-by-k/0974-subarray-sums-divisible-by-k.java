class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        int curSum = 0, ans = 0, n = nums.length;
        HashMap<Integer, Integer>mp = new HashMap<>();
        mp.put(0, 1);
        for(int i=0; i<n; i++) {
            curSum += nums[i];
            int rem = (curSum%k + k)%k;
            if(mp.containsKey(rem)) {
                ans += mp.get(rem);
            }
            mp.put(rem, mp.getOrDefault(rem, 0) + 1);
        }
        return ans;
    }
}