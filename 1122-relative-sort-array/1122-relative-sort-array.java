class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        Map<Integer, Integer>mp = new TreeMap<>();
        for(int x:arr1) mp.put(x, mp.getOrDefault(x, 0) + 1);
        int ans[] = new int[arr1.length];
        int ind = 0;
        for(int x:arr2) {
            if(mp.containsKey(x)) {
                while(mp.get(x) > 0) {
                    ans[ind++] = x;
                    mp.put(x, mp.get(x) - 1);
                }
            }
        }
        for(int x:mp.keySet()) {
            while(mp.get(x) > 0) {
                ans[ind++] = x;
                mp.put(x, mp.get(x) - 1);
            }
        }
        return ans;
    }
}