class Solution {
public:
    string fractionAddition(string s) {
        int n = s.size(), dem = 1, num = 0, i = 0;
        while(i < n) {
            int ldem = 0, lnum = 0, isNeg = 1;
            if(s[i] == '-' || s[i] == '+') {
                if(s[i++] == '-') isNeg = -1;
            }
            // extract the local numerator
            while(i < n && isdigit(s[i])) {
                lnum = lnum * 10 + (s[i++] - '0');
            }
            // update i -> expression '/'
            i++;
            // extract the local demorator
            while(i < n && isdigit(s[i])) {
                ldem = ldem * 10 + (s[i++] - '0');
            }
            lnum = lnum * isNeg;
            // a/b + c/d => (cb + ad)/bd
            num = num * ldem + lnum * dem;
            dem = dem * ldem;
        }
        int common = __gcd(abs(num), abs(dem));
        num = num/common;
        dem = dem/common;
        return to_string(num) + "/" + to_string(dem);
    }
};
// a/b + c/d = > cb + ad/bd