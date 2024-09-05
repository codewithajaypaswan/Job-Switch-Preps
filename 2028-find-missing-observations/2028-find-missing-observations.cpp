class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        long sum1 = 0;
        vector<int>ans;
        for(int r:rolls) sum1 += r;
        long sum2 = (long) mean * (long)(n + rolls.size()) - sum1;
        int num = sum2/n;
        int rem = sum2%n;
        if((num == 6 && rem != 0) || (num <= 0) || (num > 6)) return {};
        while(rem > 0) {
            ans.push_back(num + 1);
            n--; rem--;
        }
        while(n > 0) {
            ans.push_back(num);
            n--;
        }
        return ans;
    }
};