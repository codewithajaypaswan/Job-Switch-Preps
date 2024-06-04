class Solution {
    public int longestPalindrome(String s) {
        int n = s.length(), ans = 0;
        Map<Character, Integer>mp = new HashMap<>();
        for(char c:s.toCharArray()) {
            if(mp.containsKey(c)) {
                ans += 2;
                mp.remove(c);
            }
            else {
                mp.put(c, 1);
            }
        }
        if(!mp.isEmpty()) ans += 1;
        return ans;
    }
}