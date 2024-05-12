class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer>mp = new HashMap<>();
        int ans = 0;
        for(int high = 0, low = 0; high < s.length(); high++) {
            mp.put(s.charAt(high), mp.getOrDefault(s.charAt(high), 0) + 1);
            while(mp.get(s.charAt(high)) > 1) {
                mp.put(s.charAt(low), mp.getOrDefault(s.charAt(low), 0) -1);
                low++;
            }
            ans = Math.max(ans, high - low + 1);
        }
        return ans;
    }
}