class Solution {
    int[] dx = {1, 0, -1, 0};
    int[] dy = {0, 1, 0, -1};
    public boolean check(List<List<Integer>> grid, int cnt) {
        int n = grid.size();
        if(grid.get(0).get(0) < cnt) return false;
        boolean[][] vis = new boolean[n][n];
        Queue<int[]> q = new LinkedList<>();
        vis[0][0] = true;
        q.add(new int[]{0, 0});
        while (!q.isEmpty()) {
            int sz = q.size();
            while (sz-- > 0) {
                int[] temp = q.poll();
                int x = temp[0], y = temp[1];
                if (x == n - 1 && y == n - 1) return true;
                for (int i = 0; i < 4; i++) {
                    int curX = dx[i] + x, curY = dy[i] + y;
                    if (curX < 0 || curX >= n || curY < 0 || curY >= n || vis[curX][curY]) continue;
                    if (grid.get(curX).get(curY) <  cnt) continue;
                    q.add(new int[]{curX, curY});
                    vis[curX][curY] = true;
                    
                }
            }
        }
        return false;
    }
    public int maximumSafenessFactor(List<List<Integer>> grid) {
        int n = grid.size();
        Queue<int[]> q = new LinkedList<>();
        boolean[][] vis = new boolean[n][n];
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid.get(i).get(j) == 1) {
                    q.add(new int[]{i, j});
                    vis[i][j] = true;
                    grid.get(i).set(j, 0);
                }
            }
        }
        int dist = 1;
        while(!q.isEmpty()) {
            int sz = q.size();
            while(sz-- > 0) {
                int[]temp = q.poll();
                int x = temp[0], y = temp[1];
                for(int i=0; i<4; i++) {
                    int curX = x + dx[i], curY = y + dy[i];
                    if(curX < 0 || curY < 0 || curX >= n || curY >= n || vis[curX][curY]) continue;
                    q.add(new int[]{curX, curY});
                    vis[curX][curY] = true;
                    grid.get(curX).set(curY, dist);
                }
            }
            dist++;
        }
        int low = 0, high = (int) 1e9, ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(grid, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
}