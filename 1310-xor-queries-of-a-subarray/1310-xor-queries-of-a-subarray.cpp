class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int>prefixXor(n+1);
        for(int i=0; i<n; i++) {
            prefixXor[i+1] = prefixXor[i] ^ arr[i];
        }
        vector<int>ans;
        for(auto q:queries) {
            ans.push_back(prefixXor[q[1]+1] ^ prefixXor[q[0]]);
        }
        return ans;
    }
};