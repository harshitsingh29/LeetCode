class Solution {

    public boolean inside(int row, int col, int n, int m) {
        if(row >= 0 && row < n && col >= 0 && col < m) {
            return true;
        }
        return false;
    }

    public int numIslands(char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int ans = 0;
        List<int[]> li = List.of(
            new int[]{-1,0},
            new int[]{1,0},
            new int[]{0,1},
            new int[]{0,-1}
        );
        boolean[][] vis = new boolean[n][m];
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j] == false && grid[i][j] == '1') {
                    ans++;
                    Queue<int[]> q = new LinkedList<>();
                    q.add(new int[]{i,j});
                    while(!q.isEmpty()) {
                        int[] p = q.poll();
                        for(int[] it : li) {
                            int nr = p[0] + it[0];
                            int nc = p[1] + it[1];
                            if(inside(nr, nc, n, m) && !vis[nr][nc] && grid[nr][nc] == '1') {
                                q.add(new int[]{nr, nc});
                                vis[nr][nc] = true;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
}