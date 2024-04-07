class Solution {
public:
    vector<int>fact, digit;
    string ans;
    void solve(int n, int k) {
        if(n == 1) {
            ans += to_string(digit[0]);
            return;
        }
        int ind = k/fact[n-1];
        ans += to_string(digit[ind]);
        k = (k%fact[n-1]);
        digit.erase(digit.begin() + ind);
        solve(n-1, k);
    }
    string getPermutation(int n, int k) {
        fact.resize(n), digit.resize(n);
        for(int i=0; i<n; i++) {
            digit[i] = i+1;
        }
        fact[0] = 1;
        for(int i=1; i<n; i++) {
            fact[i] = fact[i-1] * i;
        }
        solve(n, k-1);
        return ans;
    }
};