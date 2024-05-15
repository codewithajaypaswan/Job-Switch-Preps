class Solution {
    public int[] dailyTemperatures(int[] temp) {
        int n = temp.length;
        int[] ans = new int[n];
        Stack<Pair<Integer, Integer>>st = new Stack<>();
        for(int i=0; i<n; i++) {
            while(!st.isEmpty() && st.peek().getValue() < temp[i]) {
                ans[st.peek().getKey()] = i - st.peek().getKey();
                st.pop();
            }
            st.push(new Pair<>(i, temp[i]));
        }
        return ans;
    }
}