class Solution {
    public int duplicateNumbersXOR(int[] nums) {
        Map<Integer, Integer>mp = new HashMap<>();
        for(int i=0; i<nums.length; i++) 
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
        int ans = 0;
        for(int x:mp.keySet()) {
            int val = mp.get(x);
            if(val == 2) ans ^= x;
        }
        return ans;
    }
}