class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        int n = profit.length;
        List<Pair<Integer, Integer>> list = new ArrayList<>();
        for(int i=0; i<n; i++) {
            list.add(new Pair<>(difficulty[i], profit[i]));
        }
        Collections.sort(list, Comparator.comparingInt(Pair::getKey));
        Arrays.sort(worker);
        int ind = 0, mx = 0, ans = 0;
        for(int i=0; i<worker.length; i++) {
            while(ind < n && worker[i] >= list.get(ind).getKey()) {
                mx = Math.max(mx, list.get(ind).getValue());
                ind++;
            }
            ans += mx;
        }
        return ans;
    }
}