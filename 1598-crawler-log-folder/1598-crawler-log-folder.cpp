class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<char>st;
        for(string s:logs) {
            if(s[1] == '.' && !st.empty()) st.pop();
            if(s[0] != '.') st.push(s[1]);
        }
        return st.size();
    }
};