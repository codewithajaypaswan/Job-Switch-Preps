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
        char[] ch = s.toCharArray();
        Arrays.sort(ch);
        return new String(ch);
    }
}