class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>prev_smaller(n, -1), next_smaller(n, n);
        stack<int>st;
        for(int i=0; i<n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(!st.empty()) prev_smaller[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if(!st.empty()) next_smaller[i] = st.top();
            st.push(i);
        }
        long long ans = 0, mod = 1e9+7;
        for(int i=0; i<n; i++) {
            int leftSmaller = i - prev_smaller[i];
            int rightSmaller = next_smaller[i] - i;
            ans = (ans%mod + (1LL * arr[i] * leftSmaller * rightSmaller)%mod)%mod;
        }
        return ans;
    }
};