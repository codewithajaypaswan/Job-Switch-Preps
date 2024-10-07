class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        for(char c:s) {
            st.push(c);
            while(!st.empty()) {
                if(st.top() == 'B') {
                    char ch = st.top(); st.pop();
                    if(!st.empty() && st.top() == 'A') st.pop();
                    else {
                        st.push(ch);
                        break;
                    }
                }
                else if(st.top() == 'D') {
                    char ch = st.top(); st.pop();
                    if(!st.empty() && st.top() == 'C') st.pop();
                    else {
                        st.push(ch);
                        break;
                    }
                }
                else break;
            }
        }
        return st.size();
    }
};