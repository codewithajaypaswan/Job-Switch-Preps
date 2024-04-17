class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int num1 = '.', num2 = '.';
        int n = nums.size();
        for(int x:nums) {
            if(x == num1) count1++;
            else if(x == num2) count2++;
            else if(count1 == 0) {
                num1 = x;
                count1 = 1;
            }
            else if(count2 == 0) {
                num2 = x;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }
        
        count1 = 0, count2 = 0;
        vector<int>ans;
        for(int x:nums) {
            if(x == num1) count1++;
            else if(x == num2) count2++;
        }
        if(count1 > n/3) ans.push_back(num1);
        if(count2 > n/3) ans.push_back(num2);
        return ans;
    }
};