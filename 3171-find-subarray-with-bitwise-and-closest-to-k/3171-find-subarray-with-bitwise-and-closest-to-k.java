class Solution {
    public int minimumDifference(int[] nums, int k) {
        Set<Integer>prev = new HashSet<>();
        int ans = Integer.MAX_VALUE;
        for(int x:nums) {
            Set<Integer>next = new HashSet<>();
            for(int p:prev) {
                next.add(p&x);
            }
            next.add(x);
            for(int n:next) {
                ans = Math.min(ans, Math.abs(n - k));
            }
            prev = next;
        }
        return ans;
    }
}