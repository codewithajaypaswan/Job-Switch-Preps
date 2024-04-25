class Solution {
public:
    string countAndSay(int n) {
        if(n == 0) return "";
        string res = "1";
        while(--n) {
            int i=0; 
            string temp = "";
            while(i < res.size()) {
                int count = 1;
                while(i+1 < res.size() && res[i] == res[i+1]) {
                    count++;
                    i++;
                }
                temp += to_string(count) + res[i];
                i++;
            }
            res = temp;
        }
        return res;
    }
};