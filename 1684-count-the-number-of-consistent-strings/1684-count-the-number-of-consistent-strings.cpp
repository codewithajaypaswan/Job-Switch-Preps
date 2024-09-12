class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char>st(allowed.begin(), allowed.end());
        int cnt = 0;
        for(string w:words) {
            bool flag = true;
            for(char c:w) {
                if(!st.count(c)) {
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        return cnt;
    }
};