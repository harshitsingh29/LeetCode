class Solution {
public:
    
    int ans(int n, int m, vector<vector<int>>& grid, int k) {
        vector<vector<int>> vis(n, vector<int>(m,-1));
        queue<vector<int>> q;
        q.push({0,0,0,k});
        while(!q.empty()) {
            auto t = q.front();
            q.pop();
            int x = t[0];
            int y = t[1];
            if(x < 0 || x > n-1 || y < 0 || y > m-1) {
                continue;
            }
            if(x == n-1 and y == m-1) {
                return t[2];
            }
            if(grid[x][y]) {
                if(t[3] > 0) {
                    t[3]--;
                }
                else {
                    continue;
                }
            }
            if(vis[x][y] != -1 and vis[x][y] >= t[3]) {
                continue;
            }
            vis[x][y] = t[3];
            q.push({x+1,y,t[2]+1,t[3]});
            q.push({x-1,y,t[2]+1,t[3]});
            q.push({x,y-1,t[2]+1,t[3]});
            q.push({x,y+1,t[2]+1,t[3]});
        }
        return -1;
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        return ans(n,m,grid,k);
    }
};