class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        int major = '.', count = 1;
        for(int x:nums) {
            if(x == major) count++;
            else count--;
            if(count == 0) {
                major = x;
                count = 1;
            }
        }
        return major;
    }
};