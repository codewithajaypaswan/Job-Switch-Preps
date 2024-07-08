class Solution {
public:
    vector<string>ans;
    vector<string> validStrings(int n) {
        string temp = "";
        solve(n, temp);
        return ans;
    }
    void solve(int n, string temp) {
        if(n == 0) {
            ans.push_back(temp);
            return;
        }
        if(temp.empty()) {
            solve(n-1, temp + '0');
            solve(n-1, temp + '1');
        }
        else if(temp.back() == '1') {
            solve(n-1, temp + '1');
            solve(n-1, temp + '0');
        }
        else {
            solve(n-1, temp + '1');
        }
    }
};