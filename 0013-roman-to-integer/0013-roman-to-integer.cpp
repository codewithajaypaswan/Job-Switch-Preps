class Solution {
public:
    int romanToInt(string s) {
        int ans = 0, n = s.size(), temp = 0, cur;
        for(char c:s) {
            if(c == 'I') cur = 1;
            else if(c == 'V') cur = 5;
            else if(c == 'X') cur = 10;
            else if(c == 'L') cur = 50;
            else if(c == 'C') cur = 100;
            else if(c == 'D') cur = 500;
            else if(c == 'M') cur = 1000;
            ans += cur;
            if(temp < cur) {
                ans -= 2 * temp;
            }
            temp = cur;
        }
        return ans;
    }
};