class Solution {
    public int longestPalindrome(String s) {
        int n = s.length(), ans = 0;
        HashSet<Character> hs = new HashSet<>();
        for(int i=0; i<n; i++) {
            char ch = s.charAt(i);
            if(hs.contains(ch)) {
                ans+=2;
                hs.remove(ch);
            }
            else {
                hs.add(ch);
            } 
        }
        if(!hs.isEmpty()) ans++;
        return ans;
    }
}