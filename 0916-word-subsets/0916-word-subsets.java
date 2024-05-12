class Solution {
    boolean subset(int[] freq1, int[] freq2) {
        for(int i=0; i<26; i++) {
            if(freq1[i] < freq2[i]) return false;
        }
        return true;
    }
    public List<String> wordSubsets(String[] words1, String[] words2) {
        List<String>ans = new ArrayList<>();
        int []freq2 = new int [26];
        for(String str:words2) {
            int []temp = new int[26];
            for(char c:str.toCharArray()) {
                temp[c - 'a']++;
                freq2[c - 'a'] = Math.max(freq2[c - 'a'], temp[c - 'a']);
            }
        }
        for(String str:words1) {
            int []freq1 = new int [26];
            for(char c:str.toCharArray()) freq1[c - 'a']++;
            if(subset(freq1, freq2)) {
                ans.add(str);
            }
        }
        return ans;
    }
}