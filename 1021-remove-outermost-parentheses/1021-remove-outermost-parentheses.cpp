class Solution {
public:
    string removeOuterParentheses(string s) {
        int open = 0;
        string ans = "";
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') {
                open++;
                if(open > 1) ans += s[i];
            }
            else {
                open--;
                if(open > 0) ans += s[i];
            }
        }
        return ans;
    }
};