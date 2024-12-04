class Solution {
public:
    int smallestNumber(int n) {
        int ans = 0;
        for(int i=31; i>=0; i--) {
            if(n&(1<<i)) {
                ans = (1<<(i+1)) - 1;
                break;
            }
        }
        return ans;
    }
};