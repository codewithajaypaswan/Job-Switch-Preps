class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int, int>mp;
        for(auto x:tasks) mp[x]++;
        int maxFreq = 0;
        for(auto it:mp) {
            maxFreq = max(maxFreq, it.second);
        }
        
        // Let's Say there are MaxFreq is A whose count is M
        // so to Arrange M-1 element of A we can do in a (M - 1) * (N + 1) ways
        // (N+1) because we consider the cycle for A also
        // now we only have to check if that maxFreq is actually occur for how many times
        
        int ans = (maxFreq - 1) * (n + 1);
        for(auto it:mp) {
            if(maxFreq == it.second) ans++;
        }
        return max(ans, (int)(tasks.size()));
    }
};