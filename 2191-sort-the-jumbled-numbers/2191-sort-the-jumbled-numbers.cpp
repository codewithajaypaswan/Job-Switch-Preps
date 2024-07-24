class Solution {
public:
    int mapValue(int x, vector<int>& mapping) {
        if(x == 0) return mapping[0];
        string ans = "";
        while(x > 0) {
            ans += '0' + mapping[x%10];
            x = x/10;
        }
        reverse(ans.begin(), ans.end());
        return stoi(ans);
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int>ans;
        vector<pair<int, int>>vp;
        for(int org:nums) {
            int x = mapValue(org, mapping);
            vp.push_back({x, org});
        }
        sort(vp.begin(), vp.end(), [&](pair<int, int>&A, pair<int, int>&B) {
            if(A.first == B.first) return false;
            else return A.first < B.first;
        });
        for(auto it:vp) {
            ans.push_back(it.second);
        }
        return ans;
    }
    static bool cmp(pair<int, int>&A, pair<int, int>&B) {
        return A.first == B.first ? false : A.first < B.first;
    }
};