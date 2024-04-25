class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        string s = normalize(pattern);
        for(string w:words) {
            if(normalize(w) == s) {
                ans.push_back(w);
            }
        }
        return ans;
    }
    string normalize(string s) {
        string str = "";
        int cnt = 0;
        unordered_map<char, char>mp;
        for(char c:s) {
            if(mp.find(c) != mp.end()) {
                str += mp[c];
            }
            else {
                char ch = (cnt + 'a');
                cnt++;
                mp[c] = ch;
                str += ch;
            }
        }
        return str;
    }
};