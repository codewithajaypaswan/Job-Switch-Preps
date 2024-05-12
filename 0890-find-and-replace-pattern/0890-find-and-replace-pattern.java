class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> ans = new ArrayList<>();
        String pat = normalize(pattern);
        for(String str:words) {
            if(pat.equals(normalize(str))) {
                ans.add(str);
            }
        }
        return ans;
    }
    String normalize(String str) {
        HashMap<Character, Character>mp = new HashMap<>();
        int cnt = 0;
        StringBuilder ans = new StringBuilder();
        for(char c:str.toCharArray()) {
            if(mp.containsKey(c)) {
                ans.append(mp.get(c));
            }
            else {
                char ch = (char)('a' + cnt);
                ans.append(ch);
                mp.put(c, ch);
                cnt++;
            }
        }
        return ans.toString();
    }
}