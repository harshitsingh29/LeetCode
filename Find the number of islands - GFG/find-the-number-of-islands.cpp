//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    void bfs(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        vis[i][j] = 1;
        queue<pair<int,int>> qu;
        qu.push({i,j});
        int n = grid.size();
        int m = grid[0].size();
        while(!qu.empty()) {
            i = qu.front().first;
            j = qu.front().second;
            qu.pop();
            for(int p=-1; p <= 1; p++) {
                for(int q=-1; q <= 1; q++) {
                    if(i+p < n and i+p > -1 and j+q < m and  j+q > -1 and grid[i+p][j+q] == '1' and vis[i+p][j+q] == 0) 
                    {
                        int nrow = i+p;
                        int ncol = j+q;
                        vis[i+p][j+q] = 1;
                        qu.push({nrow, ncol});
                    }
                }
            }
        }
    }
    
    
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1' and vis[i][j] == 0) {
                    ans++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends