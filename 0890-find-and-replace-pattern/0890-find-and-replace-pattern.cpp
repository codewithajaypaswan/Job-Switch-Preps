class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        pattern = normalize(pattern);
        for(string w:words) {
            if(pattern == normalize(w)) {
                ans.push_back(w);
            }
        }
        return ans;
    }
    
    string normalize(string &str) {
        unordered_map<char, char>mp;
        int cnt = 0;
        string ans = "";
        for(auto c:str) {
            if(mp.find(c) != mp.end()) {
                ans += mp[c];
            }
            else {
                char ch = ('a' + cnt);
                ans += ch;
                cnt++;
                mp[c] = ch;
            }
        }
        return ans;
    }
};