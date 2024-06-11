class Solution {
    List<List<Integer>>ans = new ArrayList<>();
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<Integer>temp = new ArrayList<>();
        Arrays.sort(candidates);
        solve(candidates, target, temp, 0);
        return ans;
    }
    private void solve(int[] arr, int target, List<Integer>temp, int cur) {
        if(target == 0) {
            ans.add(new ArrayList<>(temp));
            return;
        }
        if(target < 0) return;
        for(int i=cur; i<arr.length; i++) {
            temp.add(arr[i]);
            solve(arr, target - arr[i], temp, i);
            temp.remove(temp.size() - 1);
        }
    }
}