class Solution {
public:
    bool isHappy(int n) {
        int fast = n, slow = n;
        while(fast && slow) {
            fast = next(fast);
            fast = next(fast);
            slow = next(slow);
            if(fast == 1) return true;
            if(fast == slow) return false;
        }
        return false;
    }
    int next(int n) {
        int ans = 0;
        while(n > 0) {
            int rem = n%10;
            ans += rem*rem;
            n = n/10;
        }
        return ans;
    }
};