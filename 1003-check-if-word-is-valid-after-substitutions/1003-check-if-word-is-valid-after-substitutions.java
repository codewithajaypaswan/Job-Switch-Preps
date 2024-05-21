class Solution {
    public boolean isValid(String s) {
        int n = s.length();
        Stack<Character> st = new Stack<>();
        for(int i=0; i<n; i++) {
            if(s.charAt(i) == 'a' || s.charAt(i) == 'b') st.push(s.charAt(i));
            else if(s.charAt(i) == 'c' && st.size() >= 2) {
                char c = s.charAt(i) , b = st.pop(), a = st.pop();
                if(b == 'b' && a == 'a') continue;
                else {
                    st.push(a);
                    st.push(b);
                    st.push(c);
                }
            }
            else {
                st.push(s.charAt(i));
            }
        }
        return st.isEmpty();
    }
}