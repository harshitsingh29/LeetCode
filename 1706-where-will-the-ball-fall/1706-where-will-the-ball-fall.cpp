class Solution {
public:
    
    int funutil(vector<vector<int>>& grid, int n, int m, int i, int j) {
        if(i == n) {
            return j;
        }
        if(j+1 < m and grid[i][j] == 1 and grid[i][j+1] == 1) {
            return funutil(grid, n, m, i+1, j+1);
        }
        if(j-1 >= 0 and grid[i][j] == -1 and grid[i][j-1] == -1) {
            return funutil(grid, n, m, i+1, j-1);
        }
        return -1;
    }
    
    
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> ans(m);
        for(int i = 0; i < m; i++) {
            ans[i] = funutil(grid, n, m, 0, i);
        }
        return ans;
    }
};