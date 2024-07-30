class Solution {
public:
    int minimumDeletions(string s) {
        int cntb = 0, res = 0;
        for (auto & x: s) {
            if (x == 'a') res = min(res+1, cntb);
            else if (x == 'b') ++cntb;
        }
        return res;
    }
};