class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int>mp;
        while(n != 1) {
            if(mp.find(n) != mp.end()) return false;
            mp[n]++;
            n = next(n);
        }
        return true;
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