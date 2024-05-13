class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>str;
        s += " ";
        string temp = "";
        for(int i=0; i<s.size(); i++) {
            if(s[i] == ' ') {
                str.push_back(temp);
                temp = "";
            }
            else {
                temp += s[i];
            }
        }
        unordered_map<string, char>mp1;
        unordered_map<char, string>mp2;
        if(str.size() != pattern.size()) return false;
        for(int i=0; i<pattern.size(); i++) {
            if(mp1.find(str[i]) != mp1.end()) {
                if(mp1[str[i]] != pattern[i]) return false;
            }
            if(mp2.find(pattern[i]) != mp2.end()) {
                if(mp2[pattern[i]] != str[i]) return false;
            }
            mp1[str[i]] = pattern[i];
            mp2[pattern[i]] = str[i];
        }
        return true;
    }
};