class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>mp;
        int ans = 0;
        for(auto a:answers) {
            if(a == 0) {
                ans++;
            }
            else if(mp[a] == 0) {
                ans += (a+1);
            }
            mp[a]++;
            if(mp[a] == a+1) mp[a] = 0;
        }
        return ans;
    }
};