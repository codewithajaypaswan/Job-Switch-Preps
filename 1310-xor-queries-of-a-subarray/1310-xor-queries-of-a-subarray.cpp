class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int>ans, prefix(n+1, 0);
        for(int i=0; i<n; i++) {
            prefix[i+1] = prefix[i] ^ arr[i];
        }
        for(auto it:queries) {
            int l = it[0], r = it[1];
            ans.push_back(prefix[r+1] ^ prefix[l]);
        }
        return ans;
    }
};