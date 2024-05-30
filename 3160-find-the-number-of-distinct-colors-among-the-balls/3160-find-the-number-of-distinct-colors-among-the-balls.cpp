class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int>ans;
        unordered_map<int, int>mp, count;
        set<int>st;
        int dist = 0;
        for(auto q:queries) {
            int pos = q[0], color = q[1];
            // pos is new
            if(mp.find(pos) == mp.end()) {
                if(count[color] == 0) dist++;
                count[color]++;
                
                mp[pos] = color;
                ans.push_back(dist);
            }
            else {
                int prevColor = mp[pos];
                count[prevColor]--;
                if(count[prevColor] == 0) dist--;
                if(count[color] == 0) dist++;
                count[color]++;
                // cout<<count[color]<<" "<<count[prevColor]<<endl;
                mp[pos] = color;
                ans.push_back(dist);
            }
        }
        return ans;
    }
};