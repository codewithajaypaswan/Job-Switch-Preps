class Solution {
public:
    string solveEquation(string s) {
        int n = s.size(), flag = 1, x = 0, num = 0, sign = 1, i = 0;
        while(i < n) {
            int sign = 1;
            if(s[i] == '+') {
                sign = 1;
                i++;
            }
            if(s[i] == '-') {
                sign = -1;
                i++;
            }
            if(s[i] == '=') {
                flag = -1;
                i++;
            }
            if(s[i] == 'x') {
                x += flag * sign;
                i++;
            }
            if(isdigit(s[i])) {
                // isdigit(s[i])
                int val = 0;
                while(i < n && isdigit(s[i])) {
                    val = val * 10 + (s[i++] - '0');
                }
                if(i < n && s[i] == 'x') {
                    x += flag * sign * val;
                    i++;
                }
                else {
                    num += sign * flag * val;
                }
            }
            // cout<<x<<" "<<num<<endl;
        }
        if(x == 0 && num == 0) return "Infinite solutions";
        else if(x == 0) return "No solution";
        else return "x="+to_string(num/x * -1);
    }
};