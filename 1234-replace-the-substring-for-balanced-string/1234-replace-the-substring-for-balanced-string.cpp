class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int>mp;
        for(char c:s) {
            mp[c]++;
        }
        int k = s.size()/4, ans = 1e9;
        for(int high = 0, low = 0; high < s.size(); high++) {
            mp[s[high]]--;
            while(low < s.size() && mp['Q'] <= k && mp['W'] <= k && mp['E'] <= k && mp['R'] <= k) {
                ans = min(ans, high - low + 1);
                mp[s[low++]]++;
            }
        }
        return ans;
    }
};

/*

E.g s = QWQWERQW
n = 8, K = n/4 = 2
After we calculate the frequencies in the first for loop, it would be {Q=3, W=3, E=1, R=1}
Now comes the part where we want to know the count outside the window. The idea is that if the count of each character outside the window is less than equal to K, then we can replace the elements inside the window with the missing characters (it does not matter what characters are inside the window), but if the count of any of the character outside the window is more than K, then no matter what you put inside the window, it will still remain unbalanced.

e.g. When j = 1 [Q] - count outside window {Q=2, W=3, E=1, R=1} (Not possible, W = 3 > K)
j = 2 [Q,W] - count outside window {Q=2, W=2, E=1, R=1} (Our answer as count of all chars outside window <= K)

*/
