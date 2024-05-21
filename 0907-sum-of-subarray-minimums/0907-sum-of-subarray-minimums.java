class Solution {
    public int sumSubarrayMins(int[] arr) {
        int n = arr.length;
        int[] prev_smaller = new int[n];
        int[] next_smaller = new int[n];
        Arrays.fill(prev_smaller, -1);
        Arrays.fill(next_smaller, n);
        Stack<Integer> st = new Stack<>();
        for(int i=0; i<n; i++) {
            while(!st.isEmpty() && arr[st.peek()] >= arr[i]) st.pop();
            if(!st.isEmpty()) prev_smaller[i] = st.peek();
            st.push(i);
        }
        while(!st.isEmpty()) st.pop();
        for(int i=n-1; i>=0; i--) {
            while(!st.isEmpty() && arr[st.peek()] > arr[i]) st.pop();
            if(!st.isEmpty()) next_smaller[i] = st.peek();
            st.push(i);
        }
        long ans = 0;
        long mod = (long) 1e9 + 7;
        for(int i=0; i<n; i++) {
            long leftSmaller = i - prev_smaller[i];
            long rightSmaller = next_smaller[i] - i;
            ans = (ans%mod + (arr[i] * (leftSmaller%mod * rightSmaller%mod)%mod)%mod)%mod;
        }
        return (int) (ans % mod);
    }
}