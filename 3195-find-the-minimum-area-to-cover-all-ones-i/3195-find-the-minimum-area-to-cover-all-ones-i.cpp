class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int>horizonal, vertical;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    horizonal.push_back(j);
                    vertical.push_back(i);
                }
            }
        }
        int h1 = *min_element(horizonal.begin(), horizonal.end());
        int h2 = *max_element(horizonal.begin(), horizonal.end());
        int v1 = *min_element(vertical.begin(), vertical.end());
        int v2 = *max_element(vertical.begin(), vertical.end());
        return (h2 - h1 + 1) * (v2 - v1 + 1);
    }
};

/*

a --- b
|     |
c --- d
horizonal = 0, 1, 2
vertical = 0,1
0,1
1,0
1,2

*/
