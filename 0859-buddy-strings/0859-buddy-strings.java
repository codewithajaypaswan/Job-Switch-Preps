class Solution {
    public boolean buddyStrings(String s, String goal) {
        if(s.length() != goal.length()) return false;
        if(s.equals(goal)) {
            int []freq = new int[26];
            for(int i=0; i<s.length(); i++) {
                freq[s.charAt(i) - 'a']++;
            }
            for(int i=0; i<26; i++) {
                if(freq[i] >= 2) return true;
            }
        }
        else {
            int x = -1;
            for(int i=0; i<s.length(); i++) {
                if(s.charAt(i) != goal.charAt(i)) {
                    if(x == -1) x = i;
                    else {
                        StringBuilder sb = new StringBuilder(s);
                        sb.setCharAt(x, s.charAt(i));
                        sb.setCharAt(i, s.charAt(x));
                        return goal.equals(sb.toString());
                    }
                }
            }
        }
        return false;
    }
}