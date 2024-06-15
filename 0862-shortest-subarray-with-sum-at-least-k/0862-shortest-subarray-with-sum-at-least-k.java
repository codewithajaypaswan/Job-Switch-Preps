public class Solution {
    public int shortestSubarray(int[] nums, int k) {
        int n = nums.length;
        long ans = Long.MAX_VALUE;
        Deque<long[]> dq = new LinkedList<>();
        long sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            
            if (sum >= k) {
                ans = Math.min(ans, i + 1);
            }
            
            while (!dq.isEmpty() && sum - dq.peekFirst()[1] >= k) {
                ans = Math.min(ans, i - dq.pollFirst()[0]);
            }
            
            while (!dq.isEmpty() && sum <= dq.peekLast()[1]) {
                dq.pollLast();
            }
            
            dq.addLast(new long[]{i, sum});
        }
        
        return ans == Long.MAX_VALUE ? -1 : (int) ans;
    }
}