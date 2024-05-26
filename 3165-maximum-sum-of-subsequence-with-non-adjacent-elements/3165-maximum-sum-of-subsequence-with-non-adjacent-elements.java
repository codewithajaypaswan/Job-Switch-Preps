class Solution {
    public int maximumSumSubsequence(int[] nums, int[][] queries) {
        final int MOD = 1_000_000_007;
        int n = nums.length;
        long sumOfAnswers = 0;
        long[] dpInclude = new long[n];
        long[] dpExclude = new long[n];
     
        dpInclude[0] = Math.max(0, nums[0]);
        dpExclude[0] = 0;
        
        for (int i = 1; i < n; i++) {
            dpInclude[i] = dpExclude[i - 1] + Math.max(0, nums[i]);
            dpExclude[i] = Math.max(dpInclude[i - 1], dpExclude[i - 1]);
        }
        
        for (int[] query : queries) {
            int pos = query[0];
            int val = query[1];
            nums[pos] = val; 
            
            if (pos == 0) {
                dpInclude[0] = Math.max(0, nums[0]);
                dpExclude[0] = 0;
                pos = 1;
            }
            
            for (int i = pos; i < n; i++) {
                dpInclude[i] = dpExclude[i - 1] + Math.max(0, nums[i]);
                dpExclude[i] = Math.max(dpInclude[i - 1], dpExclude[i - 1]);
            }
            
            long currentMaxSum = getMaxSum(dpInclude, dpExclude, n);
            sumOfAnswers = (sumOfAnswers + currentMaxSum) % MOD;
        }
        
        return (int) sumOfAnswers;
    }

    private long getMaxSum(long[] dpInclude, long[] dpExclude, int n) {
        return Math.max(dpInclude[n - 1], dpExclude[n - 1]);
    }
}