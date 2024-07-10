class Solution {
    public int minOperations(String[] logs) {
        Stack<Character>st = new Stack<>();
        for(String s:logs) {
            if(s.charAt(1) == '.' && !st.isEmpty()) st.pop();
            if(s.charAt(0) != '.') st.push(s.charAt(0));
        }
        return st.size();
    }
}