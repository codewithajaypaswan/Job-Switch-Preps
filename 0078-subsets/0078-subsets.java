class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    void solve(int[]nums, int index, List<Integer>temp) {
        if(index >= nums.length) {
            ans.add(new ArrayList<>(temp));
            return;
        }
        ans.add(new ArrayList<>(temp));
        for(int i=index; i<nums.length; i++) {
            temp.add(nums[i]);
            solve(nums, i+1, temp);
            temp.remove(temp.size()-1);
        }
    }
    public List<List<Integer>> subsets(int[] nums) {
        solve(nums, 0, new ArrayList<>());
        return ans;
    }
}