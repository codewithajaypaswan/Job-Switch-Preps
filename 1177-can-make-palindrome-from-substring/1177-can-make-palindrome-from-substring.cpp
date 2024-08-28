class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<vector<int>>v(n+1, vector<int>(26, 0));
        for(int i=1; i<=n; i++) {
            for(int j=0; j<26; j++) v[i][j] = v[i-1][j];
            v[i][s[i-1] - 'a']++;
        }
        // for(int i=0; i<=n; i++) {
        //     for(int j=0; j<26; j++) {
        //         cout<<v[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<bool>ans;
        for(auto q:queries) {
            int l = q[0], r = q[1], k = q[2];
            int cnt = 0;
            for(int i=0; i<26; i++) {
                cnt += (v[r+1][i] - v[l][i])%2;
            }
            cout<<cnt<<endl;
            if(cnt/2 <= k) {
                ans.push_back(true);
            }
            else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};