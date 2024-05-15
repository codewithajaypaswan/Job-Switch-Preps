class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char>st;
        for(int i=0; i<n; i++) {
            while(!st.empty() && st.top() > num[i] && k > 0) {
                st.pop();
                k--;
            }
            if(st.empty() && num[i] == '0') continue;
            st.push(num[i]);
        }
        while(!st.empty() && k > 0) {
            st.pop();
            k--;
        }
        string ans = "";
        while(!st.empty()) {
            ans += st.top(); st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans.empty() ? "0" : ans;
    }
};