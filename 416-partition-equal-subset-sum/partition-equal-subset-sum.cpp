class Solution {
public:

    bool solution(vector<int>& nums, int ind, int sum, vector<vector<int>>& dp) {
        if(sum == 0) {
            return true;
        }
        if(sum < 0 || ind == nums.size()) {
            return false;
        }
        if(dp[ind][sum] != -1) {
            return dp[ind][sum];
        }
        return dp[ind][sum] = solution(nums, ind+1, sum-nums[ind],dp) || solution(nums, ind+1, sum,dp);
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if(sum%2) {
            return false;
        }
        vector<vector<int>> dp(nums.size()+1, vector<int>(sum+1,-1));
        return solution(nums, 0, sum/2,dp);
    }
};