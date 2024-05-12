class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size(), m = b.size();
        int i = n-1, j = m-1, carry = 0;
        string ans = "";
        while(i >=0 && j >= 0) {
            int val = (a[i] - '0') + (b[j] - '0') + carry;
            ans += (val)%2 + '0';
            carry = val/2;
            i--; j--;
        }
        while(i >= 0) {
            int val = (a[i] - '0') + carry;
            ans += (val)%2 + '0';
            carry = val/2;
            i--;
        }
        while(j >= 0) {
            int val = (b[j] - '0') + carry;
            ans += (val)%2 + '0';
            carry = val/2;
            j--;
        }
        if(carry) {
            ans += '0' + carry;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};