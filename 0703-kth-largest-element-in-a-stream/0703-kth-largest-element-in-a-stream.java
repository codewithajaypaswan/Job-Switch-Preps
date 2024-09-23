class KthLargest {
    int size;
    PriorityQueue<Integer>pq;
    public KthLargest(int k, int[] nums) {
        size = k;
        pq = new PriorityQueue<>();
        for(int x:nums) {
            pq.add(x);
            if(pq.size() > k) pq.poll();
        }
    }
    
    public int add(int val) {
        pq.add(val);
        if(pq.size() > size) pq.poll();
        return pq.peek();
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */