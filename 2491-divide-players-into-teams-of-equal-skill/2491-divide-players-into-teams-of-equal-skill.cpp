class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long sum = 0, ans = 0;
        for(int s:skill) sum += s;
        int equal = skill.size()/2;
        if(sum%equal != 0) return -1;
        int k = sum / equal;
        unordered_map<int, int>mp;
        for(int x:skill) {
            if(mp[k - x] > 0) {
                mp[k - x]--;
                ans += x * (k - x);
            }
            else {
                mp[x]++;
            }
        }
        for(auto it:mp) {
            if(it.second > 0) return -1;
        }
        return ans;
    }
};