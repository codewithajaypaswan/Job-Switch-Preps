class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        queue<int>q;
        vector<int>ans(n);
        sort(deck.begin(), deck.end());
        for(int i=0; i<n; i++) {
            q.push(i);
        }
        for(int i=0; i<n; i++) {
            int cur = q.front(); q.pop();
            ans[cur] = deck[i];
            int next = q.front(); q.pop();
            q.push(next);
        }
        return ans;
    }
};