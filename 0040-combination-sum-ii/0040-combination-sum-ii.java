class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        solve(candidates, target, new ArrayList<>(), 0);
        return ans;
    }
    private void solve(int[] arr, int target, List<Integer>temp, int cur) {
        if(target == 0) {
            ans.add(new ArrayList<>(temp));
            return;
        }
        if(target < 0 || cur >= arr.length) return;
        Set<Integer>st = new HashSet<>();
        for(int i=cur; i<arr.length; i++) {
            if(st.contains(arr[i])) continue;
            st.add(arr[i]);
            temp.add(arr[i]);
            solve(arr, target - arr[i], temp, i+1);
            temp.remove(temp.size()-1);
        }
    }
}