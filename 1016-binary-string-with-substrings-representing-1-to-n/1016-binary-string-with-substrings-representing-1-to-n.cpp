class Solution {
public:
    bool queryString(string s, int n) {
        for(int i=1;i<=n;i++){
            bitset<32>b(i);
            string str = b.to_string();
            int one = str.find("1");
            string digit = str.substr(one);
            if(s.find(digit) == -1) return false;
        }
        return true;
    }
};