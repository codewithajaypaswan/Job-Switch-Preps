class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    void solve(int[]nums, int index, List<Integer>temp) {
        if(index >= nums.length) {
            ans.add(new ArrayList<>(temp));
            return;
        }
        Set<Integer>st = new HashSet<>();
        ans.add(new ArrayList<>(temp));
        for(int i=index; i<nums.length; i++) {
            if(st.contains(nums[i])) continue;
            st.add(nums[i]);
            temp.add(nums[i]);
            solve(nums, i+1, temp);
            temp.remove(temp.size()-1);
        }
    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        solve(nums, 0, new ArrayList<>());
        return ans;
    }
}