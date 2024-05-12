class Solution {
    public String customSortString(String order, String s) {
        Map<Character, Integer>mp = new HashMap<>();
        for(int i=0; i<s.length(); i++) {
            mp.put(s.charAt(i), mp.getOrDefault(s.charAt(i), 0) + 1);
        }
        StringBuilder sb = new StringBuilder();
        for(char c:order.toCharArray()) {
            if(mp.containsKey(c)) {
                for(int i=0; i<mp.get(c); i++) {
                    sb.append(c);
                }
                mp.remove(c);
            }
        }
        // Iterator<Character> it = mp.keySet().iterator();
        // while(it.hasNext()) {
        //     char c = it.next();
        //     for(int i=0; i<mp.get(c); i++) {
        //         sb.append(c);
        //     }
        //     it.remove();
        // }
        for(char c : mp.keySet()) {
            for(int i=0; i<mp.get(c); i++) {
                sb.append(c);
            }
        }
        return sb.toString();
    }
}