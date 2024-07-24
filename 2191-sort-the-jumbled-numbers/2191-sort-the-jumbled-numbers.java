class Solution {
    int mapValue(int[] mapping, int org) {
        int ans = 0, power = 1;
        if(org == 0) return mapping[0];
        while(org > 0) {
            ans = power * mapping[org%10] + ans;
            org = org/10;
            power = power * 10;
        }
        return ans;
    }
    public int[] sortJumbled(int[] mapping, int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        List<int[]> lp = new ArrayList<>();
        for(int org:nums) {
            int val = mapValue(mapping, org);
            lp.add(new int[] {val, org});
        }
        System.out.println(lp);
        Collections.sort(lp, (a, b) -> {
           if(a[0] == b[0]) return 0;
            return a[0] - b[0];
        });
        for(int i=0; i<n; i++) {
            ans[i] = lp.get(i)[1];
        }
        return ans;
    }
}