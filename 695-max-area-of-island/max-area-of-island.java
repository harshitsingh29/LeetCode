class Solution {

    public boolean inside(int r, int c, int n, int m) {
        return (r >= 0 && r < n && c >= 0 && c < m);
    }

    public int maxAreaOfIsland(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        List<int[]> li = List.of(
            new int[]{0,1},
            new int[]{0,-1},
            new int[]{1,0},
            new int[]{-1,0}
        );
        boolean[][] vis = new boolean[n][m];
        Queue<int[]> q = new LinkedList<>();
        int max_ans = 0, cur_ans = 0;
        for(int i = 0; i < n; i++) {
            cur_ans = 0;
            for(int j = 0; j < m; j++) {
                if(vis[i][j] == false && grid[i][j] == 1) {
                    q.add(new int[]{i,j});
                    vis[i][j] = true;
                    cur_ans++;
                    System.out.println(i + " " + j);
                    while(!q.isEmpty()) {
                        int[] p = q.poll();
                        int f = p[0];
                        int s = p[1];
                        for(int[] it : li) {
                            int nr = f + it[0];
                            int nc = s + it[1];
                            if(inside(nr, nc, n, m) && vis[nr][nc] == false && grid[nr][nc] == 1) {
                                vis[nr][nc] = true;
                                q.add(new int[]{nr, nc});
                                cur_ans++;
                                System.out.println(nr + " " + nc);
                            }
                        }
                    }
                    System.out.println(cur_ans);
                    max_ans = Math.max(max_ans, cur_ans);
                    cur_ans = 0;
                }
            }
        }
        return max_ans;
    }
}