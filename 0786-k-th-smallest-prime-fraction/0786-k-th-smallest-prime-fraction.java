class Solution {
    public int[] kthSmallestPrimeFraction(int[] arr, int k) {
        PriorityQueue<Pair>pq = new PriorityQueue<Pair>();
        for(int i=0; i<arr.length; i++) {
            pq.add(new Pair((double)arr[0]/arr[i], 0, i));
        }
        while(k-- > 1) {
            Pair cur = pq.poll();
            if(cur.x + 1 < arr.length) {
                pq.add(new Pair((double)arr[cur.x+1]/arr[cur.y], cur.x+1, cur.y));
            }
        }
        Pair cur = pq.poll();
        return new int[] {arr[cur.x], arr[cur.y]};
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