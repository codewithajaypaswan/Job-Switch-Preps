class Solution {
public:
    string removeOuterParentheses(string s) {
        int open = 0, n = s.size();
        string ans = "";
        for(int i=0; i<n; i++) {
            if(s[i] == '(') {
                if(open > 0) ans += s[i];
                open++;
            }
            else {
                if(open > 1) ans += s[i];
                open--;
            }
        }
        return ans;
    }
};