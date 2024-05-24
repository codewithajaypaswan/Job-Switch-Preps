class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int>freq(26, 0);
        for(char c:letters) {
            freq[c - 'a']++;
        }
        return solve(words, score, freq, 0);
    }
    int solve(vector<string>&words, vector<int>&score, vector<int>&freq, int cur) {
        if(cur >= words.size()) return 0;
        int noTake = solve(words, score, freq, cur + 1);
        int take = 0, flag = 0, curScore = 0;
        string str = words[cur];
        for(char c:str) {
            if(freq[c - 'a'] == 0) {
                flag = 1;
            }
            freq[c - 'a']--;
            curScore += score[c - 'a'];
        }
        if(flag == 0) {
            // take
            take = curScore + solve(words, score, freq, cur+1);
        }
        for(char c:str) {
            freq[c - 'a']++;
        }
        return max(take, noTake);
    }
};