class Solution {
public:
    int passThePillow(int n, int time) {
        int cur = 1, dir = 1;
        while(time--) {
            cur += dir;
            if(cur == n || cur == 1) {
                dir *= -1;
            }
        }
        return cur;
    }
};