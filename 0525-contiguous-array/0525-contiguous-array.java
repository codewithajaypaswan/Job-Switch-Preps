class Solution {
    public int findMaxLength(int[] nums) {
        HashMap<Integer, Integer>mp = new HashMap<>();
        int ans = 0, sum = 0;
        mp.put(0, -1);
        for(int i=0; i<nums.length; i++) {
            sum += nums[i] == 0 ? -1 : 1;
            if(mp.containsKey(sum)) {
                ans = Math.max(ans, i - mp.get(sum));
            }
            else {
                mp.put(sum, i);
            }
        }
        return ans;
    }
}