class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int cnt = 1, i = 0, n = sentence.size();
        while(i < n) {
            bool flag = true;
            int s_i = 0;
            while(i < n && sentence[i] != ' ') {
                if(flag && s_i < searchWord.size() && searchWord[s_i] == sentence[i]) {
                    i++;
                    s_i++;
                    if(s_i == searchWord.size()) return cnt;
                }
                else {
                    flag = false;
                    i++;
                }
            }
            i++;
            cnt++;
        }
        return -1;
    }
};