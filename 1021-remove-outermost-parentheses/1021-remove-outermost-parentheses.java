class Solution {
    public String removeOuterParentheses(String s) {
        int open = 0, n = s.length();
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<n; i++) {
            if(s.charAt(i) == '(') {
                if(open > 0) sb.append(s.charAt(i));
                open++;
            }
            else {
                if(open > 1) sb.append(s.charAt(i));
                open--;
            }
        }
        return sb.toString();
    }
}