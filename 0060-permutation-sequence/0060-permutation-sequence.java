class Solution {
    List<Integer> fact = new ArrayList<>();
    List<Integer> digit = new ArrayList<>();
    StringBuilder sb = new StringBuilder();
    void solve(int n, int k) {
        if(n == 1) {
            sb.append(Integer.toString(digit.get(0)));
            return;
        }
        int ind = k/fact.get(n-1);
        k = (k%(fact.get(n-1)));
        sb.append(Integer.toString(digit.get(ind)));
        digit.remove(ind);
        solve(n-1, k);
    }
    public String getPermutation(int n, int k) {
        for(int i=0; i<n; i++) {
            digit.add(i+1);
        }
        fact.add(1);
        for(int i=1; i<n; i++) {
            fact.add(fact.get(i-1) * i);
        }
        solve(n, k-1);
        return sb.toString();
    }
}