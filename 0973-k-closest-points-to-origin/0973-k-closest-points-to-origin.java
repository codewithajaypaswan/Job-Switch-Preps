class Solution {
    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((p1, p2) -> {
            return (p2[0] * p2[0] + p2[1] * p2[1]) - (p1[0] * p1[0] + p1[1] * p1[1]);
            });
        for(int[]p : points) {
            pq.add(p);
            if(pq.size() > k) pq.poll();
        }
        int[][] ans = new int[k][2];
        for(int i=0; i<k; i++) {
            ans[i] = pq.poll();
        }
        return ans;
    }
}

/*

class Solution {
    public double distance(int[] p1) {
        return Math.sqrt((p1[0] * p1[0]) + (p1[1] * p1[1]));
    }
    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<Pair>pq = new PriorityQueue<>(Collections.reverseOrder());
        int n = points.length;
        for(int i=0; i<n; i++) {
            pq.add(new Pair(distance(points[i]), points[i][0], points[i][1]));
            if(pq.size() > k) pq.poll();
        }
        int size = pq.size();
        int[][] ans = new int[size][2];
        for(int i=0; i<size; i++) {
            Pair cur = pq.poll();
            ans[i][0] = cur.x;
            ans[i][1] = cur.y;
        }
        return ans;
    }
    public class Pair implements Comparable<Pair> {
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

*/