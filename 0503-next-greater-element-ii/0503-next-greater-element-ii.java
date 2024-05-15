class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length;
        Stack<Integer>st = new Stack<>();
        int[] ans = new int[n];
        Arrays.fill(ans, -1);
        for(int k=0; k<2*n; k++) {
            int i = k%n;
            while(!st.isEmpty() && nums[st.peek()] < nums[i]) {
                ans[st.pop()] = nums[i];
            }
            st.push(i);
        }
        return ans;
    }
}