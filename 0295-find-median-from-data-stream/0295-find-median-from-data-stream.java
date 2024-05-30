class MedianFinder {
    PriorityQueue<Integer>mn;
    PriorityQueue<Integer>mx;
    public MedianFinder() {
        mn = new PriorityQueue();
        mx = new PriorityQueue(Collections.reverseOrder());
    }
    
    public void addNum(int num) {
        if(mx.isEmpty()) {
            mx.offer(num);
        }
        else if(mx.size() == mn.size()) {
            if(num > mn.peek()) {
                int x = mn.poll();
                mx.offer(x);
                mn.offer(num);
            }
            else {
                mx.offer(num);
            }
        }
        else {
            if(num < mx.peek()) {
                int x = mx.poll();
                mn.offer(x);
                mx.offer(num);
            }
            else {
                mn.offer(num);
            }
        }
    }
    
    public double findMedian() {
        if(mx.size() == mn.size()) {
            return (double) (mx.peek() + mn.peek())/2;
        }
        else {
            return (double) mx.peek();
        }
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */