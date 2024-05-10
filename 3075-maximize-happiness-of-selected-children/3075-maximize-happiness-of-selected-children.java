class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for(int i=0; i<happiness.length; i++) {
            pq.add(happiness[i]);
        }
        long ans = 0, cnt = 0;
        while(!pq.isEmpty() && k-- > 0) {
            int x = pq.poll();
            x -= cnt;
            if(x <= 0) return ans;
            ans += x;
            cnt++;
        }
        return ans;
    }
}