class Solution {
    public long sumDigitDifferences(int[] nums) {
        long ans = 0, n = nums.length;
        int[][] freq = new int[10][10];
        for(int x:nums) {
            for(int i=0; x>0; i++) {
                freq[i][x%10]++;
                x = x/10;
            }
        }
        for(int i=0; i<freq.length; i++) {
            for(int j=0; j<freq[0].length; j++) {
                ans += (long) freq[i][j] * (nums.length - freq[i][j]);
            }
        }
        return ans/2;
    }
}