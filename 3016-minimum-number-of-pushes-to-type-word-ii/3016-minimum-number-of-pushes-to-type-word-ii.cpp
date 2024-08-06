class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26, 0);
        for(char c:word) {
            freq[c - 'a']++;
        }
        int ans = 0, row = 1;
        sort(freq.begin(), freq.end(), greater<int>());
        for(int i=0; i<26; i++) {
            if(freq[i] == 0) continue;
            if(i != 0 && i%8 == 0) row++;
            ans += freq[i] * row;
        }
        return ans;
    }
};