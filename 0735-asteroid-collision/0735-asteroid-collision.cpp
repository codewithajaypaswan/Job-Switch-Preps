class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int x:asteroids) {
            bool destroy = false;
            while(!st.empty() && x < 0 && st.top() > 0 && !destroy) {
                if(abs(x) < st.top()) {
                    destroy = true;
                }
                else if(abs(x) > st.top()) {
                    st.pop();
                }
                else {
                   st.pop();
                   destroy = true;
                }
            }
            if(!destroy) st.push(x);
        }
        vector<int>ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};