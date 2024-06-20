class Solution {
public:
    bool check(int mid, vector<int>&position, int m) {
        int cur = position[0], cnt = 1;
        for(int i=1; i<position.size(); i++) {
            if(position[i] - cur >= mid) {
                cnt++;
                cur = position[i];
            }
        }
        return cnt >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int low = 0, high = position[n-1], ans = -1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(check(mid, position, m)) {
                ans = mid;
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return ans;
    }
};