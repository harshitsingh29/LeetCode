class Solution {
public:
    
    int f(int ind, int cap, int buy, int n, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if(ind == n || cap == 0) return 0;
        
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        
        if(buy) {
            return dp[ind][buy][cap] = max(-prices[ind] + f(ind+1, cap, 0, n, prices, dp), f(ind+1, cap, 1, n, prices, dp));
        }
        return dp[ind][buy][cap] = max(prices[ind]+f(ind+1, cap-1, 1, n, prices, dp), f(ind+1, cap, 0, n, prices, dp));
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(), vector<vector<int>>(2, vector<int>(3,-1)));
        return f(0, 2, 1, prices.size(), prices, dp);
    }
};