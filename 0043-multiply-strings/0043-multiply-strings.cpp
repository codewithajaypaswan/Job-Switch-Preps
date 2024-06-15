class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size(), m = num2.size();
        string ans(n+m, '0');
        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                int mul = (ans[i+j+1]-'0') + (num1[i] - '0') * (num2[j] - '0');
                ans[i+j+1] = (mul%10)+'0';
                ans[i+j] += (mul/10);
            }
        }
        int i;
        for(i=0; i<n+m; i++) {
            if(ans[i] != '0') return ans.substr(i);
        }
        return "0";
    }
};