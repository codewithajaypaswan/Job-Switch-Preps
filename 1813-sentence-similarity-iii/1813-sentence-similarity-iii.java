class Solution {
    public boolean areSentencesSimilar(String sentence1, String sentence2) {
        String[] s1 = sentence1.split(" ");
        String[] s2 = sentence2.split(" ");
        if(s1.length < s2.length) {
            String[] temp = s1;
            s1 = s2;
            s2 = temp;
        }
        int start = 0, end = 0;
        while(start < s2.length && s1[start].equals(s2[start])) start++;
        while(end < s2.length && s1[s1.length - 1 - end].equals(s2[s2.length - 1 - end])) end++;
        return start + end >= s2.length;
    }
}