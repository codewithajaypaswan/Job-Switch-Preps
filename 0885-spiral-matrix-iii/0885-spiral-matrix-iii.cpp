class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>ans;
        int dir = 0, len = 0;
        ans.push_back({rStart, cStart});
        while(ans.size() < rows*cols) {
            if(dir == 0 || dir == 2) len++;
            for(int i=0; i<len; i++) {
                rStart += dx[dir];
                cStart += dy[dir];
                if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                    ans.push_back({rStart, cStart});
                }
            }
            dir = (dir + 1)%4;
        }
        return ans;
    }
};