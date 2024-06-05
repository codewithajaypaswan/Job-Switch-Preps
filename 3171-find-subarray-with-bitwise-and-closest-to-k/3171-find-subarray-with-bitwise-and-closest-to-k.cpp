class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        set<int>prev;
        int ans = INT_MAX;
        for(int x:nums) {
            set<int>next;
            for(int p:prev) {
                next.insert(x&p);
            }
            next.insert(x);
            for(int n:next) {
                ans = min(ans, abs(n - k));
            }
            prev = next;
        }
        return ans;
    }
};