class Solution {
    public boolean isValidSerialization(String preorder) {
        String[] nodes = preorder.split(",");
        int cnt = 1;
        for(int i=0; i<nodes.length; i++) {
            cnt--;
            if(cnt < 0) return false;
            if(!nodes[i].equals("#")) cnt += 2;
        }
        return cnt == 0;
    }
}