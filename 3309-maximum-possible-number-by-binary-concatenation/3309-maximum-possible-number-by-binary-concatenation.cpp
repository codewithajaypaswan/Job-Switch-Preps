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
    int maxGoodNumber(vector<int>& nums) {
        string s1 = decimalToBinary(nums[0]);
        string s2 = decimalToBinary(nums[1]);
        string s3 = decimalToBinary(nums[2]);
        string str1 = s1 + s2 + s3;
        string str2 = s1 + s3 + s2;
        string str3 = s2 + s1 + s3;
        string str4 = s2 + s3 + s1;
        string str5 = s3 + s1 + s2;
        string str6 = s3 + s2 + s1;
        return max({solve(str1), solve(str2), solve(str3), solve(str4), solve(str5), solve(str6)});
    }
};