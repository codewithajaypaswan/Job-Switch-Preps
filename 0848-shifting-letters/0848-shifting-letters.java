class Solution {
    public String shiftingLetters(String s, int[] shifts) {
        int n = shifts.length;
        for(int i=n-2; i>=0; i--) {
            shifts[i] += shifts[i+1]%26;
        }
        StringBuilder sb = new StringBuilder(s);
        for(int i=0; i<s.length(); i++) {
            char ch = (char) ('a' + (shifts[i] + s.charAt(i) - 'a')%26);
            sb.setCharAt(i, ch);
        }
        return sb.toString();
    }
}