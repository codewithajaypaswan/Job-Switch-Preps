class Solution {
    public String decodeAtIndex(String s, int k) {
        long len = 0;
        for(int i=0; i<s.length(); i++) {
            if(s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                len *= (s.charAt(i) - '0');
            }
            else {
                len++;
            }
        }
        for(int i=s.length()-1; i>=0; i--) {
            k = (int) (k%len);
            if(k == 0 && !Character.isDigit(s.charAt(i))) {
                return Character.toString(s.charAt(i));
            }
            else if(s.charAt(i) >= '0' && s.charAt(i) <= '9') len /= (s.charAt(i) - '0');
            else len--;
        }
        return "";
    }
}