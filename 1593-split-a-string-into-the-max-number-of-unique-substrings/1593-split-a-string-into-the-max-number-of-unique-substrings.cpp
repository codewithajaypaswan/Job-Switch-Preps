class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string>st;
        return solve(s, 0, st);
    }
    int solve(string &s, int cur, unordered_set<string>&st) {
        if(cur >= s.size()) {
            return 0;
        }
        int maxSplit = 0;
        for(int i=cur; i<s.size(); i++) {
            string temp = s.substr(cur, i - cur + 1);
            if(st.find(temp) == st.end()) {
                st.insert(temp);
                maxSplit = max(maxSplit, 1 + solve(s, i+1, st));
                st.erase(temp);
            }
        }
        return maxSplit;
    }
};