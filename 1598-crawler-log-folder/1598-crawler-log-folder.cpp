class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt = 0;
        for(string s:logs) {
            if(s[1] == '.' && cnt != 0) cnt--;
            if(s[0] != '.') cnt++;
        }
        return cnt;
    }
};