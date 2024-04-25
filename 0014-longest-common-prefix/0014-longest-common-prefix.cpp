class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        if(s.empty()) return "";
        string ans = "";
        for(int i=0; i<s[0].size(); i++) {
            char ch = s[0][i];
            int flag = true;
            for(int j=1; j<s.size(); j++) {
                if(s[j][i] != ch) {
                    flag = false;
                    break;
                }
            }
            if(flag) ans += ch;
            else break;
        }
        return ans;
    }
};