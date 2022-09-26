class Solution {
public:
    
    int ans(int i, int j, int m, int n, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        if(i > m-1 || j > n-1) {
            return 0;
        }
        if(i == m-1 and j == n-1 and mat[i][j] != 1) {
            return 1;
        }
        if(mat[i][j] == 1) {
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        
        int res = 0;
        res = ans(i+1,j,m,n,mat,dp) + ans(i,j+1,m,n,mat,dp);
        return dp[i][j] = res;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp(101, vector<int>(101, -1));
        return ans(0,0,m,n,mat,dp);
    }
};