class Solution {
    public int maxScoreWords(String[] words, char[] letters, int[] score) {
        int[] freq = new int[26];
        for(char c: letters) {
            freq[c - 'a']++;
        }
        return solve(words, score, freq, 0);
    }
    int solve(String[] words, int[] score, int[] freq, int cur) {
        if(cur >= words.length) return 0;
        int noTake = solve(words, score, freq, cur+1);
        int flag = 1, take = 0, curScore = 0;
        String str = words[cur];
        for(char c:str.toCharArray()) {
            if(freq[c - 'a'] == 0) {
                flag = 0;
            }
            freq[c - 'a']--;
            curScore += score[c - 'a'];
        }
        if(flag == 1) {
            take = curScore + solve(words, score, freq, cur+1);
        }
        for(char c:str.toCharArray()) {
            freq[c - 'a']++;
        }
        return Math.max(take, noTake);
    }
}