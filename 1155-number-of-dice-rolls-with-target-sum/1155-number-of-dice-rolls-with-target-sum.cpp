class Solution {
public:
    int mod = 1000000007;
    int f(int i, int n, int k, int target, vector<vector<int>>& dp) {
        if(target < 0) return 0;
        if(target == 0 and i == n) {
            return 1;
        }
        if(i == n) return 0;
        if(dp[i][target] != -1) return dp[i][target];
        int res = 0;
        for(int j = 1; j <= min(k,target); j++) {
            res = (res + f(i+1,n,k,target-j,dp) % mod)%mod;
        }
        return dp[i][target] = res % mod;
        
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n, vector<int>(target+1,-1));
        return f(0,n,k,target,dp);
    }
};