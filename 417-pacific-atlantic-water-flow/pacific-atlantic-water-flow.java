class Solution {

    public boolean checkpacificAtlantic(int i, int j, int n, int m, int[][] heights) {
        boolean[][] vis = new boolean[n][m];
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{i,j});
        boolean pacific = false;
        boolean atlantic = false;
        List<int[]> dx = List.of(
            new int[]{0,1},
            new int[]{1,0},
            new int[]{-1,0},
            new int[]{0,-1}
        );
        vis[i][j] = true;
        while(!q.isEmpty()) {
            int[] arr = q.poll();
            int a = arr[0];
            int b = arr[1];
            if(a == 0 || b == 0) {
                pacific = true;
            }
            if(a == n-1 || b == m-1) {
                atlantic = true;
            }
            if(pacific == true && atlantic == true) {
                return true;
            }
            for(int[] it : dx) {
                int nr = a + it[0];
                int nc = b + it[1];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == false && heights[nr][nc] <= heights[a][b]) {
                    vis[nr][nc] = true;
                    q.add(new int[]{nr,nc});
                }
            }

        }
        return false;
    }

    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        List<List<Integer>> ans = new ArrayList<>();
        int n = heights.length;
        int m = heights[0].length;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if((i == 0 && j == m-1) || (i == n-1 && j == 0)) {
                    List<Integer> li = new ArrayList<>();
                    li.add(i);
                    li.add(j);
                    ans.add(li);
                }
                else {
                    boolean flag = checkpacificAtlantic(i,j,n,m,heights);
                    if(flag) {
                        List<Integer> li = new ArrayList<>();
                        li.add(i);
                        li.add(j);
                        ans.add(li);
                    }
                }
            }
        }
        return ans;
    }
}