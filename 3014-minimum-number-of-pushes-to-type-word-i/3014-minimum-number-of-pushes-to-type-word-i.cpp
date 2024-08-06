class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26, 0);
        for(char c:word) {
            freq[c - 'a']++;
        }
        sort(freq.rbegin(), freq.rend());
        int row = 1, ans = 0;
        for(int i=0; i<26; i++) {
            if(freq[i] == 0) continue;
            if(i > 7 && i%8 == 0) row++;
            ans += freq[i] * row;
        }
        return ans;
    }
};