class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int n = word.size();
        for(int i=0, cnt = 0; i<n; i++) {
            if(i+1 < n && word[i] == word[i+1]) {
                cnt++;
                if(cnt == 9) {
                    ans += to_string(cnt) + word[i];
                    cnt = 0;
                }
            }
            else {
                cnt++;
                ans += to_string(cnt) + word[i];
                cnt = 0;
            }
        }
        return ans;
    }
};