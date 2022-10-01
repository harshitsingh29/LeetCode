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
        vector<vector<int>>dp(n, vector<int>(mm,1e7));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < mm; j++) {
                if(i == 0) dp[i][j] = m[i][j];
                else {
                    int l, r;
                    if(j > 0) {
                        l = m[i][j] + dp[i-1][j-1];
                    }
                    else {
                        l = 1e7;
                    }
                    
                    if(j < mm-1) {
                        r = m[i][j] + dp[i-1][j+1];
                    }
                    else {
                        r = 1e7;
                    }
                    
                    int u = m[i][j] + dp[i-1][j];
                    
                    dp[i][j] = min({u,l,r});
                    
                }
            }
        }
        for(int j = 0; j < mm; j++) {
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
    }
};