class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char>st;
        for(int i=0; i<n; i++) {
            while(!st.empty() && st.top() > num[i] && k > 0) {
                k--;
                st.pop();
            }
            if(st.empty() && num[i] == '0') continue;
            st.push(num[i]);
        }
        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        num = "";
        while(!st.empty()) {
            num += st.top(); st.pop();
        }
        reverse(num.begin(), num.end());
        return num == "" ? "0" : num;
    }
};