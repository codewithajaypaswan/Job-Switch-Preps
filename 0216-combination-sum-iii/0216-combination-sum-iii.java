class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<Integer>temp = new ArrayList<>();
        solve(k, n, temp, 1);
        return ans;
    }
    private void solve(int k, int target, List<Integer>temp, int cur) {
        if(target == 0 && k == 0) {
            ans.add(new ArrayList<>(temp));
            return;
        }
        if(target < 0 || k < 0) return;
        for(int i=cur; i<=9; i++) {
            temp.add(i);
            solve(k-1, target - i, temp, i+1);
            temp.remove(temp.size()-1);
        }
    }
}