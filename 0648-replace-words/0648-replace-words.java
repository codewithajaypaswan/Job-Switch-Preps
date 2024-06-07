class Solution {
    public String replaceWords(List<String> dictionary, String sentence) {
        Set<String>st = new HashSet<>();
        for(String s:dictionary) {
            st.add(s);
        }
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<sentence.length(); i++) {
            StringBuilder str = new StringBuilder();
            while(i < sentence.length() && sentence.charAt(i) != ' ') {
                str.append(sentence.charAt(i));
                i++;
                if(st.contains(str.toString())) {
                    while(i < sentence.length() && sentence.charAt(i) != ' ') i++;
                }
            }
            sb.append(str);
            sb.append(" ");
        }
        sb.deleteCharAt(sb.length() - 1);
        String ans = sb.toString();
        return ans;
    }
}