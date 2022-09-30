class Solution {
public:
    
    int tridp(int i, int j, int n,vector<vector<int>>& mat, vector<vector<int>>& dp) {
        if(i == n-1) {
            return mat[i][j];
        } 
        if(i > n-1) {
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX;
        dp[i][j] = mat[i][j] + min(tridp(i+1, j, n, mat, dp), tridp(i+1, j+1, n, mat, dp));
        return dp[i][j];
    }
    
    int minimumTotal(vector<vector<int>>& mat) {
        int n = mat.size(); 
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return tridp(0,0,n,mat, dp);
    }
};