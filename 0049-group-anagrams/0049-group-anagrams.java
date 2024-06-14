class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>>mp = new HashMap<>();
        for(String s:strs) {
            String sorted = sortString(s);
            if(!mp.containsKey(sorted)) {
                mp.put(sorted, new ArrayList<>());
            }
            mp.get(sorted).add(s);
        }
        List<List<String>>ans = new ArrayList<>();
        for(Map.Entry<String, List<String>> e:mp.entrySet()) {
            ans.add(e.getValue());
        }
        return ans;
    }
    String sortString(String s) {
        StringBuilder sb = new StringBuilder();
        int[]freq = new int[26];
        for(char c:s.toCharArray()) {
            freq[c - 'a']++;
        }
        for(int i=0; i<26; i++) {
            if(freq[i] > 0) {
                while(freq[i]-- > 0) {
                    sb.append((char) ((int)'a' + i));
                }
            }
        }
        return sb.toString();
    }
}