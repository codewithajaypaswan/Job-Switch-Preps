class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>left(n, 0), right(n, 0);
        int leftMax = height[0];
        for(int i=0; i<n; i++) {
            leftMax = max(leftMax, height[i]);
            left[i] = leftMax;
        }
        int rightMax = height[n-1];
        for(int i=n-1; i>=0; i--) {
            rightMax = max(rightMax, height[i]);
            right[i] = rightMax;
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            ans += max(0, min(left[i], right[i]) - height[i]);
        }
        return ans;
    }
};