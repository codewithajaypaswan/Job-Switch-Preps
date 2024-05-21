class Solution {
    public boolean isValidSerialization(String preorder) {
        if(preorder.isEmpty()) return true;
        StringBuilder sb = new StringBuilder(preorder);
        sb.append(',');
        int cnt = 1;
        for(int i=0; i<sb.length(); i++) {
            if(sb.charAt(i) != ',') continue;
            cnt--;
            if(cnt < 0) return false;
            if(sb.charAt(i-1) != '#') cnt += 2;
        }
        return cnt == 0;
    }
}