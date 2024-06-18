class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long ans = 0, n = hours.size();
        unordered_map<long long, long long>mp;
        long long sum = 0;
        for(int i=0; i<n; i++) {
            ans += mp[(24 - hours[i]%24)%24];
            mp[hours[i]%24]++;
        }
        return ans;
    }
};