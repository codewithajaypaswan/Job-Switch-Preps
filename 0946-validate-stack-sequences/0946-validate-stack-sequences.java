class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer>st = new Stack<>();
        int n = pushed.length, k = 0;
        for(int i=0; i<n; i++) {
            st.push(pushed[i]);
            while(k < n && !st.isEmpty() && st.peek() == popped[k]) {
                st.pop();
                k++;
            }
        }
        return st.empty();
    }
}