class Solution {
    public int[] kthSmallestPrimeFraction(int[] arr, int k) {
        PriorityQueue<Pair>pq = new PriorityQueue();
        int n = arr.length;
        for(int i=0; i<n; i++) {
            pq.add(new Pair((double) arr[0]/arr[i], 0, i));
        }
        while(k-- > 1 && !pq.isEmpty()) {
            Pair it = pq.poll();
            if(it.x+1 < n) {
                pq.add(new Pair((double) arr[it.x+1]/arr[it.y], it.x+1, it.y));
            }
        }
        return new int[] {arr[pq.peek().x], arr[pq.peek().y]};
    }
    static class Pair implements Comparable<Pair> {
        double value;
        int x, y;
        Pair(double value, int x, int y) {
            this.value = value;
            this.x = x;
            this.y = y;
        }
        public int compareTo(Pair other) {
            return Double.compare(this.value, other.value);
        }
    }
}