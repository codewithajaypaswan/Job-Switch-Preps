class Solution {
    public boolean wordPattern(String pattern, String s) {
        int n = pattern.length();
        List<String> str = new ArrayList<>();
        s += " ";
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<s.length(); i++) {
            if(s.charAt(i) == ' ') {
                str.add(sb.toString());
                sb = new StringBuilder();
            }
            else {
                sb.append(s.charAt(i));
            }
        }
        if(str.size() != pattern.length()) return false;  
        Map<String, Character>mp1 = new HashMap<>();
        Map<Character, String>mp2 = new HashMap<>();
        for(int i=0; i<n; i++) {
            String curStr = str.get(i);
            char curCh = pattern.charAt(i);
            if(mp1.containsKey(curStr)) {
                if(mp1.get(curStr) != curCh) return false;
            }
            if(mp2.containsKey(curCh)) {
                if(!mp2.get(curCh).equals(curStr)) return false;
            }
            mp1.put(curStr, curCh);
            mp2.put(curCh, curStr);
        }
        return true;
    }
}