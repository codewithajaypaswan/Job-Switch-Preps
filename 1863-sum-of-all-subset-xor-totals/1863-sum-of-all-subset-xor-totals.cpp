class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int size = 1<<n;
        cout<<size<<endl;
        vector<vector<int>>arr(size);
        for(int i=0; i<size; i++) {
            for(int j=0; j<n; j++) {
                if(i&(1<<j)) arr[i].push_back(nums[j]);
            }
        }
        int ans = 0;
        for(vector<int>v: arr) {
            int temp = 0;
            for(int x:v) {
                temp ^= x;
            }
            ans += temp;
        }
        return ans;
    }
};