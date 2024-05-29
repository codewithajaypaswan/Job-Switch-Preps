class Solution {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        List<List<Integer>> ans = new ArrayList<>();
        PriorityQueue<int[]>pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        for(int i=0; i<nums1.length; i++) {
            pq.offer(new int[] {nums1[i] + nums2[0], i, 0});
        }
        while(k-- > 0 && !pq.isEmpty()) {
            int[] temp = pq.poll();
            int i = temp[1], j = temp[2];
            ans.add(Arrays.asList(nums1[i], nums2[j]));
            if(j+1 < nums2.length) {
                pq.offer(new int[] {nums1[i] + nums2[j+1], i, j+1});
            }
        }
        return ans;
    }
}