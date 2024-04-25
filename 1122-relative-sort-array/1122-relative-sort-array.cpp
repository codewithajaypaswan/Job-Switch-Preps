class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int>mp;
        for(int x:arr1) mp[x]++;
        int i = 0;
        for(int x:arr2) {
            while(mp[x] > 0) {
                arr1[i++] = x;
                mp[x]--;
            }
        }
        for(auto it:mp) {
            while(it.second > 0) {
                arr1[i++] = it.first;
                it.second--;
            }
        }
        return arr1;
    }
};