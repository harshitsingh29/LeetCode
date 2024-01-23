class Solution {

    public int bfs(Queue<int[]> q, int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        //Queue<int[]> q = new LinkedList<>();
        //q.add(new int[] { k, j, 0 });
        int ans = 0;
        int[] li = { -1, 0, 1, 0, -1 };
        while (!q.isEmpty()) {
            int[] arr = q.poll();
            int a = arr[0];
            int b = arr[1];
            int c = arr[2];
            ans = Math.max(ans, c);
            for (int i = 0; i < 4; i++) {
                int nr = li[i] + a;
                int nc = li[i + 1] + b;
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    q.add(new int[] { nr, nc, c + 1 });
                }
            }
        }
        return ans;
    }

    public int orangesRotting(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int ans = 0;
        Queue<int[]> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.add(new int[]{i,j,0});
                }
            }
        }

        ans = Math.max(bfs(q, grid), ans);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return ans;
    }
}
