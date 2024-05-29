class Solution {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        List<List<Integer>> ans = new ArrayList<>();
        PriorityQueue<int[]>pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        for(int i=0; i<nums1.length; i++) {
            pq.offer(new int[] {nums1[i] + nums2[0], i, 0});
        }
        for(int i=0; i<k && !pq.isEmpty(); i++) {
            int[] temp = pq.poll();
            int x = temp[1], y = temp[2];
            ans.add(new ArrayList<>());
            ans.get(i).add(nums1[x]);
            ans.get(i).add(nums2[y]);
            if(y+1 < nums2.length) {
                pq.offer(new int[] {nums1[x] + nums2[y+1], x, y+1});
            }
        }
        return ans;
    }
}