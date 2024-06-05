class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>ans;
        vector<int>cnt(26, INT_MAX);
        for(string s:words) {
            vector<int>cnt1(26, 0);
            for(char c:s) cnt1[c - 'a']++;
            for(int i=0; i<26; i++) cnt[i] = min(cnt[i], cnt1[i]);
        }
        for(int i=0; i<26; i++) {
            for(int j=0; j<cnt[i]; j++) {
                ans.push_back(string(1, 'a' + i));
            }
        }
        return ans;
    }
};