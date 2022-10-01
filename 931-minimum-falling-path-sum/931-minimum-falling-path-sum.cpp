class Solution {
public:
    
    int f(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        int n = mat.size();
        int m = mat[0].size();
        if(j < 0 || j > m-1) return 1e7;
        if(dp[i][j] != -1) return dp[i][j];
        if(i == n-1) return mat[i][j];
        
        int left = mat[i][j] + f(i+1,j-1,mat,dp);
        int cent = mat[i][j] + f(i+1,j,mat,dp);
        int rght = mat[i][j] + f(i+1,j+1,mat,dp);
        return dp[i][j] = min({left, rght, cent});
    }
    
    int minFallingPathSum(vector<vector<int>>& m) {
        int ans = INT_MAX;
        int n = m.size();
        int mm = m[0].size();
        vector<vector<int>>dp(n, vector<int>(mm,-1));
        for(int i = 0; i < m[0].size(); i++) {
            ans = min(ans, f(0,i,m,dp));
        }
        return ans;
    }
};