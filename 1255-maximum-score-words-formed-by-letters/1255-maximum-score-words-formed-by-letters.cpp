class Solution {
public:
    int solve(vector<string>&words, vector<int>&freq, vector<int>&score, int cur) {
        if(cur >= words.size()) return 0;
        int noTake = solve(words, freq, score, cur+1);
        int sc = 0, flag = 1, take = 0;
        for(char c:words[cur]) {
            if(freq[c - 'a'] == 0) {
                flag = 0;
            }
            freq[c - 'a']--;
            sc += score[c- 'a'];
        }
        if(flag == 1) {
            // take it
            take = sc + solve(words, freq, score, cur+1);
        }
        for(char c:words[cur]) {
            freq[c - 'a']++;
        }
        return max(take, noTake);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int>freq(26, 0);
        for(char c:letters) {
            freq[c - 'a']++;
        }
        return solve(words, freq, score, 0);
    }
};