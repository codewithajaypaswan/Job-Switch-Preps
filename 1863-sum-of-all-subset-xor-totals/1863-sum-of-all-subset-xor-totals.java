class Solution {
    public int subsetXORSum(int[] nums) {
        int n = nums.length;
        int size = 1<<n;
        List<List<Integer>> arr = new ArrayList<>();
        for(int i=0; i<size; i++) {
            List<Integer> subset = new ArrayList<>();
            for(int j=0; j<n; j++) {
                if((i&(1<<j)) > 0) {
                    subset.add(nums[j]);
                }
            }
            arr.add(subset);
        }
        
        int ans = 0;
        for(List<Integer> li : arr) {
            int temp = 0;
            for(int x:li) {
                temp ^= x;
            }
            ans += temp;
        }
        return ans;
    }
}