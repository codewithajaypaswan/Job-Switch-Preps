class Solution {
public:
    int minFlips(string target) {
        int ans = 0, state = 0;
        for(char c:target) {
            if(c - '0' != state) {
                ans++;
                state = c - '0';
            }
        }
        return ans;
    }
};