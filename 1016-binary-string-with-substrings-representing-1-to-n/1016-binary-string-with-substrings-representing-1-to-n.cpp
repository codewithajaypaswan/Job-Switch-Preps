class Solution {
public:
    bool queryString(string s, int n) {
        for(int i=1;i<=n;i++){
            bitset<32> b(i);
            string t=b.to_string();
            // cout<<t<<endl;
            int one=t.find('1');
            // cout<<one<<endl;
            string p=t.substr(one);
            // cout<<p<<endl;
            if(s.find(p)==-1){
                return false;
            }
        }
        return true;
    }
};