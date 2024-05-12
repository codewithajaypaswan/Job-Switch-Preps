class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size(), m = b.size();
        string ans;
        int i = n-1, j = m-1, num = 0;
        while(i >=0 || j>=0 || num == 1) {
            num += i>=0 ? (a[i--]-'0') : 0;
            num += j>=0 ? (b[j--]-'0') : 0;
            ans.push_back((num%2) + '0');
            num = num/2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};