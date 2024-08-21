class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size(), ans = 0;
        int cntZero = 0, cntOne = 0;
        for(int high = 0, low = 0; high < n; high++) {
            if(s[high] == '1') cntOne++;
            else cntZero++;
            while(cntOne > k && cntZero > k) {
                if(s[low] == '0') cntZero--;
                else cntOne--;
                low++;
            }
            ans += high - low + 1;
        }
        return ans;
    }
};