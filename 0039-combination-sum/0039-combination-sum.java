class Solution {
    void solve(int[] arr, List<Integer>temp, int target, int ind, List<List<Integer>> ans) {
        if(target < 0) return;
        if(target == 0) {
            ans.add(new ArrayList<Integer>(temp));
        }
        for(int i=ind; i<arr.length; i++) {
            temp.add(arr[i]);
            solve(arr, temp, target - arr[i], i, ans);
            temp.remove(temp.size() - 1);
        }
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        solve(candidates, new ArrayList<>(), target, 0, ans);
        return ans;
    }
}