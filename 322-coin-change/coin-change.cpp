class Solution {
public:

    int solution(vector<int>& coins,int ind, int price,vector<vector<int>>& dp) {
        if(price == 0) return 0;
        if(ind == coins.size() || price < 0) return 1e9;
        if(dp[ind][price] != -1) return dp[ind][price];
        return dp[ind][price] = min(1+solution(coins,ind,price-coins[ind],dp), solution(coins,ind+1, price,dp));
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1,-1));
        int k = solution(coins, 0, amount,dp);
        if(k == 1e9) return -1;
        return k;
    }
};