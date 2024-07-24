class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string ss = "", tt = "";
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '#' && !ss.empty()) ss.pop_back();
            else if(s[i] != '#') ss += s[i];
        }
        for(int i=0; i<t.size(); i++) {
            if(t[i] == '#' && !tt.empty()) tt.pop_back();
            else if(t[i] != '#') tt += t[i];
        }
        return tt == ss;
    }
};