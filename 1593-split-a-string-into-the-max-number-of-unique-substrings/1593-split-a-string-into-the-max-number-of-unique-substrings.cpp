class Solution {
public:
    int ans = 0;
    int maxUniqueSplit(string s) {
        unordered_set<string>st;
        solve(s, 0, st);
        return ans;
    }
    void solve(string &s, int cur, unordered_set<string>&st) {
        if(cur >= s.size()) {
            ans = max(ans, (int)st.size());
            return;
        }
        for(int i=cur; i<s.size(); i++) {
            string temp = s.substr(cur, i - cur + 1);
            if(st.find(temp) == st.end()) {
                st.insert(temp);
                solve(s, i+1, st);
                st.erase(temp);
            }
        }
    }
};