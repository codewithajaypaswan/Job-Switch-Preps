class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int n1 = nums1.length, n2 = nums2.length;
        int[] ans = new int[n1];
        Arrays.fill(ans, -1);
        Stack<Integer>st = new Stack<>();
        Map<Integer, Integer>mp = new HashMap<>();
        for(int i=0; i<n2; i++) {
            while(!st.isEmpty() && nums2[st.peek()] < nums2[i]) {
                mp.put(nums2[st.pop()], nums2[i]);
            }
            st.push(i);
        }
        for(int i=0; i<n1; i++) {
            if(mp.containsKey(nums1[i])) {
                ans[i] = mp.get(nums1[i]);
            }
        }
        return ans;
    }
}