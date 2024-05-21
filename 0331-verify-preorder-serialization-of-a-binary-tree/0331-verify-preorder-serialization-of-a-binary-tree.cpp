class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.empty()) return true;
        preorder += ',';
        int cnt = 1;
        for(int i=0; i<preorder.size(); i++) {
            if(preorder[i] != ',') continue;
            cnt--;
            if(cnt < 0) return false;
            if(i > 0 && preorder[i-1] != '#') cnt+=2;
        }
        return cnt == 0;
    }
};