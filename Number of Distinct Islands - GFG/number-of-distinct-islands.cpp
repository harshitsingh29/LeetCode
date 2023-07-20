//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    vector<pair<int, int>> dfs(int i, int j, int bi, int bj, int n, int m, vector<vector<int>>& vis, vector<vector<int>>& grid,vector<pair<int,int>>& v) {
        vis[i][j] = 1;
        v.push_back({bi-i, bj-j});
        int dx[] = {0,1,0,-1,0};
        for(int k = 0; k < 4; k++) {
            int dr = i + dx[k];
            int dc = j + dx[k+1];
            if(dr >= 0 and dc >= 0 and dr < n and dc < m and grid[dr][dc] == 1 and vis[dr][dc] != 1) {
                dfs(dr, dc, bi, bj, n, m, vis, grid, v);
            }
        }
        return v;
    } 
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<vector<pair<int,int>>>st;
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j] == 0 and grid[i][j] == 1) {
                    vector<pair<int,int>> v;
                    v = dfs(i,j,i,j,n,m,vis,grid,v);
                    st.insert(v);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends