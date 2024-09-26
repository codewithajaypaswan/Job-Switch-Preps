class Solution {
public:
    bool solve(int n) {
        if(n < 1) return false;
        if(n == 1) return true;
        if(n%2 == 0) return solve(n/2);
        if(n%3 == 0) return solve(n/3);
        if(n%5 == 0) return solve(n/5);
        return false;
    }
    bool isUgly(int n) {
        return solve(n);
        // while(n > 1) {
        //     if(n%2 == 0) n = n/2;
        //     else if(n%3 == 0) n = n/3;
        //     else if(n%5 == 0) n = n/5;
        //     else break;
        // }
        // return n == 1;
    }
};