class Solution {
    public int duplicateNumbersXOR(int[] nums) {
        Map<Integer, Integer>mp = new HashMap<>();
        for(int i=0; i<nums.length; i++) 
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
        int ans = 0;
        for(Map.Entry<Integer, Integer>x : mp.entrySet()) {
            int key = x.getKey();
            int val = x.getValue();
            if(val == 2) ans ^= key;
        }
        return ans;
    }
}