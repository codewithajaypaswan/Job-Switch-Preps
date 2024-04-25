class Solution {
public:
    
    bool isHappy(int n) {
        if(n == 1) return true;
        int fast = n , slow = n;
        while(true) {
            fast = getNext(fast);
            fast = getNext(fast);
            slow = getNext(slow);
            if(fast == 1) return true;
            if(slow == fast) break;
        }
        return false;
    }
    int getNext(int n) {
        int ans = 0;
        while(n > 0) {
            int rem = n%10;
            ans += rem * rem;
            n = n/10;
        }
        return ans;
    }
};