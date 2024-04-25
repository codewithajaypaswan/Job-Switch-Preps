class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>prev_smaller(n), next_smaller(n);
        stack<int>st;
        for(int i=0; i<n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) prev_smaller[i] = -1;
            else prev_smaller[i] = st.top();
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) next_smaller[i] = n;
            else next_smaller[i] = st.top();
            st.push(i);
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            int width = next_smaller[i] - prev_smaller[i] - 1;
            ans = max(ans, heights[i] * width);
        }
        return ans;
    }
};