class Solution {
    public String removeKdigits(String num, int k) {
        Stack<Character>st = new Stack<>();
        for(int i=0; i<num.length(); i++) {
            while(!st.isEmpty() && st.peek() > num.charAt(i) && k > 0) {
                st.pop();
                k--;
            }
            if(st.isEmpty() && num.charAt(i) == '0') continue;
            st.push(num.charAt(i));
        }
        while(k > 0 && !st.isEmpty()) {
            st.pop();
            k--;
        }
        StringBuilder sb = new StringBuilder();
        while(!st.isEmpty()) {
            sb.append(st.pop());
        }
        sb.reverse();
        return sb.isEmpty() ? "0" : sb.toString();
    }
}