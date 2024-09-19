class Solution {
public:
    unordered_map<string, vector<int>>mp;
    vector<int> diffWaysToCompute(string exp) {
        int n = exp.size();
        vector<int>ans;
        for(int i=0; i<exp.size(); i++) {
            if(exp[i] == '+' || exp[i] == '*' || exp[i] == '-') {
                string l = exp.substr(0, i);
                string r = exp.substr(i+1);
                vector<int>left, right;
                if(mp.find(l) != mp.end()) {
                    left = mp[l];
                }
                else {
                    left = diffWaysToCompute(l);
                }
                if(mp.find(r) != mp.end()) {
                    right = mp[r];
                }
                else {
                    right = diffWaysToCompute(r);
                }
                for(int n1:left) {
                    for(int n2:right) {
                        if(exp[i] == '+') {
                            ans.push_back(n1+n2);
                        }
                        else if(exp[i] == '-') {
                            ans.push_back(n1-n2);
                        }
                        else {
                            ans.push_back(n1*n2);
                        }
                    }
                }
            }
        }
        if(ans.empty()) {
           ans.push_back(stoi(exp)); 
        }
        return mp[exp] = ans;
    }
};