class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long ans = 0;
        vector<vector<int>>freq(10, vector<int>(10, 0));
        int n = nums.size();
        for(int x:nums) {
            for(int j=0; x > 0; j++) {
                freq[j][x%10]++;
                x /= 10;
            }
        }
        for(int i=0; i<freq.size(); i++) {
            for(int j=0; j<freq[0].size(); j++) {
                ans += freq[i][j] * (nums.size() - freq[i][j]);
            }
        }
        return ans/2;
    }
};