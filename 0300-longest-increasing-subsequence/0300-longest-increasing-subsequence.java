class Solution {
    public int lengthOfLIS(int[] nums) {
        ArrayList<Integer>arr = new ArrayList<Integer>();
        for(int i=0; i<nums.length; i++) {
            if(arr.isEmpty() || arr.get(arr.size() - 1) < nums[i]) {
                arr.add(nums[i]);
            }
            else {
                int ind = Collections.binarySearch(arr, nums[i]);
                if(ind < 0) ind = - (ind + 1);
                arr.set(ind, nums[i]);
            }
        }
        return (int) arr.size();
    }
}