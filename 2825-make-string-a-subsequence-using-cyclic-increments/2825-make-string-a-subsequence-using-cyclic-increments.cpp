class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int j = 0, n = str1.size(), m = str2.size();
        for(int i=0; i < n && j < m; i++) {
            char ch1 = str1[i], ch2 = str2[j];
            char nextChar = ch1 == 'z' ? 'a' : ch1+1;
            if(ch1 == ch2 || ch2 == nextChar) {
                j++;
            }
        }
        return j == m;
    }
};