class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        reverse(energy.begin(), energy.end());
        for(int i=k; i<energy.size(); i++) {
            energy[i] += energy[i - k];
        }
        int mx = INT_MIN;
        for(int i=0; i<energy.size(); i++) {
            mx = max(mx, energy[i]);
        }
        return mx;
    }
};