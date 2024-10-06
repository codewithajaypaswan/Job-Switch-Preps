class Solution {
public:
    string decimalToBinary(int n) {
        string s = "";
        while(n > 0) {
            s += ('0' + (n%2));
            n = n/2;
        }
        reverse(s.begin(), s.end());
        return s;
    }
    int solve(string &s) {
        int ans = 0, n = s.size();
        reverse(s.begin(), s.end());
        for(int i=0; i<n; i++) {
            ans += (1<<i) * (s[i] - '0');
        }
        return ans;
    }
    static bool cmp(string &a, string &b) {
        return a+b > b+a;
    }
    int maxGoodNumber(vector<int>& nums) {
        vector<string>str;
        for(int x:nums) {
            str.push_back(decimalToBinary(x));
        }
        sort(str.begin(), str.end(), cmp);
        string s = "";
        for(int i=0; i<str.size(); i++) s += str[i];
        return solve(s);
    }
};