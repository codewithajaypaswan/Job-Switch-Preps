class Solution {
public:
    string countOfAtoms(string formula) {
        reverse(formula.begin(), formula.end());
        map<string, int>mp;
        solve(formula, mp);
        string ans = "";
        for(auto it:mp) {
            ans += it.first;
            if(it.second > 1) {
                ans += to_string(it.second);
            }
        }
        return ans;
    }
    void solve(string s, map<string, int>&mp) {
        stack<int>st; // to store factors
        st.push(1);
        int n = s.size(), factor = 1;
        string ele = "";
        for(int i=0, num = 0; i<n; i++) {
            if(isdigit(s[i])) {
                int expo = 1;
                while(i < n && isdigit(s[i])) {
                    num += (s[i] - '0') * expo;
                    expo *= 10; 
                    i++;
                }
                i--;
                factor = num;
                num = 0;
            }
            else if(s[i] == ')') {
                st.push(factor * st.top());
                factor = 1;
            }
            else if(s[i] >= 'A' && s[i] <= 'Z') {
                ele += s[i];
                reverse(ele.begin(), ele.end());
                mp[ele] += factor*st.top();
                factor = 1;
                ele = "";
            }
            else if(s[i] >= 'a' && s[i] <= 'z') {
                ele += s[i];
            }
            else {
                st.pop();
            }
        }
    }
};