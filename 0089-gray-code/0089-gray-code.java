class Solution {
    List<Integer> ans = new ArrayList<>();
    public List<Integer> grayCode(int n) {
        solve(n);
        return ans;
    }
    void solve(int n) {
        if(n == 0) {
            ans.add(0);
            return;
        }
        solve(n-1);
        int mask = (1<<(n-1));
        for(int i=ans.size()-1; i>=0; i--) {
            ans.add(ans.get(i) ^ mask);
        }
    }
}