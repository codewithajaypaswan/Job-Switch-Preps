class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string, int>mp;
        int n = word.size();
        for(int i=0; i<=n-k; i+=k) {
            string str = word.substr(i, k);
            mp[str]++;
        }
        int mx = 0;
        for(auto it:mp) {
            mx = max(mx, it.second);
        }
        return n/k - mx;
    }
};