class Solution {
    public int totalHammingDistance(int[] nums) {
        int ans = 0, n = nums.length;
        for(int i=0; i<32; i++) {
            int one = 0;
            for(int x:nums) {
                if((x&(1<<i)) != 0) one++;
            }
            ans += one * (n - one);
        }
        return ans;
    }
}