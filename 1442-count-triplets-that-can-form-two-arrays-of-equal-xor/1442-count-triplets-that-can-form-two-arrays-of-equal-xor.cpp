class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>>mp;
        mp[0].push_back(-1);
        int x = 0, ans = 0;
        for(int i=0; i<n; i++) {
            x ^= arr[i];
            if(mp.find(x) != mp.end()) {
                for(auto index:mp[x]) {
                    ans += i - index - 1;
                }
            }
            mp[x].push_back(i);
        }
        return ans;
    }
};