class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int>ans(n1, -1);
        unordered_map<int, int>mp;
        stack<int>st;
        for(int i=0; i<n2; i++) {
            while(!st.empty() && nums2[st.top()] < nums2[i]) {
                mp[nums2[st.top()]] = nums2[i];
                st.pop();
            }
            st.push(i);
        }
        
        for(int i=0; i<n1; i++) {
            if(mp.find(nums1[i]) != mp.end()) {
                ans[i] = mp[nums1[i]];
            }
        }
        return ans;
    }
};