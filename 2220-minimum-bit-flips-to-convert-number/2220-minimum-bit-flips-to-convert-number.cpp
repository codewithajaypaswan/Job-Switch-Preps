class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        for(int i=0; i<32; i++) {
            int bit = (1<<i);
            if((start&bit) != (goal&bit)) ans++;
        }
        return ans;
    }
};