class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    void solve(int[]nums, int index, List<Integer>temp) {
        if(index >= nums.length) return;
        temp.add(nums[index]);
        ans.add(new ArrayList<>(temp));
        solve(nums, index + 1, temp);
        temp.remove(temp.get(temp.size()-1));
        solve(nums, index + 1, temp);
    }
    public List<List<Integer>> subsets(int[] nums) {
        ans.add(new ArrayList<>());
        solve(nums, 0, new ArrayList<>());
        return ans;
    }
}