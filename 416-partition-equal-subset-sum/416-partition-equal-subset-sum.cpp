class Solution {
public:
    
    bool f(int i, int sum, vector<int>& nums, vector<vector<int>>& dp) {
        int n = nums.size();
        if(sum == 0) return true;
        if(i == n-1) return (nums[i] == sum);
        if(dp[i][sum] != -1) return dp[i][sum];
        bool ans1 = false;
        if(nums[i] <= sum) ans1 = f(i+1, sum-nums[i], nums, dp);
        bool ans2 = f(i+1, sum, nums, dp);
        return dp[i][sum] = ans1 | ans2;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size(); 
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        vector<vector<int>> dp(n, vector<int>(sum/2+1, -1));
        return sum%2 == 1 ? false : f(0,sum/2,nums,dp);
    }
};