class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        int major = '.', count = 0;
        for(int x:nums) {
            if(x == major) count++;
            else if(count == 0) {
                major = x;
                count++;
            }
            else {
                count--;
            }
        }
        return major;
    }
};