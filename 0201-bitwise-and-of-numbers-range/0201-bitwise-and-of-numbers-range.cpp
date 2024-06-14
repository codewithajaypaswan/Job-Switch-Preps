class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        for(int i=31; i>=0; i--) {
            if((left&(1<<i)) != (right&(1<<i))) {
                break;
            }
            ans |= left&(1<<i);
        }
        return ans;
        // int cnt = 0;
        // while(left != right) {
        //     left >>= 1;
        //     right >>= 1;
        //     cnt++;
        // }
        // return left<<cnt;
    }
};
// 5 = 101
//     110
// 7 = 111