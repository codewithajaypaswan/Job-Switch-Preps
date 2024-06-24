class Solution {
    public int minKBitFlips(int[] nums, int k) {
        int n = nums.length, ans = 0;
        Queue<Integer>q = new LinkedList<>();
        for(int i=0; i<n; i++) {
            int val = q.size()%2 == 0 ? nums[i] : 1-nums[i];
            if(val == 0) {
                ans++;
                q.add(i+k-1);
            }
            if(!q.isEmpty() && q.peek() == i) q.poll();
        }
        return q.isEmpty() ? ans : -1;
    }
}