class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int cnt = 0, n = nums.size();
        vector<int>occX;
        for(int i=0; i<n; i++) {
            if(nums[i] == x) occX.push_back(i);
        }
        vector<int>ans;
        for(int q:queries) {
            if(q > occX.size()) ans.push_back(-1);
            else ans.push_back(occX[q-1]);
        }
        return ans;
    }
};