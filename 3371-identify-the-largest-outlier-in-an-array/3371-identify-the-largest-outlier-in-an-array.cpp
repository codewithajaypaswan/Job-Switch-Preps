class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        unordered_map<int, int>mp;
        long sum = 0;
        for(int x:nums) {
            sum += x;
            mp[x]++;
        }
        int ans = INT_MIN;
        for(int x:nums) {
            int outlier = sum - x - x;
            if(mp[outlier] > (outlier == x ? 1 : 0)) {
                ans = max(ans, outlier);
            }
        }
        return ans;
    }
};

/*
class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        unordered_map<int, int>mp;
        long sum = 0;
        for(int x:nums) {
            sum += x;
            mp[x]++;
        }
        int ans = INT_MIN;
        for(int x:nums) {
            mp[x]--;
            // x is the outliner
            long req = sum - x;
            if(req%2 != 0) {
                mp[x]++;
                continue;
            }
            long specialSum = req/2;
        
            if(mp[specialSum] > 0) {
                ans = max(ans, x);
            }
            mp[x]++;
        }
        return ans;
    }
};
*/