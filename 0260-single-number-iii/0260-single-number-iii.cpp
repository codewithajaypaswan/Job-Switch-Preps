class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xy = 0;
        for(int num:nums) {
            xy ^= num;
        }
        int dif = 0;
        for(int i=0; i<31; i++) {
            if(xy&(1<<i)) {
                dif = (1<<i);
                break;
            }
        }
        int x = 0, y = 0;
        for(int num:nums) {
            if(num&dif) {
                x ^= num;
            }
            else {
                y ^= num;
            }
        }
        return {x, y};
    }
};