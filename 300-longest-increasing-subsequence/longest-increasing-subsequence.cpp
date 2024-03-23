class Solution {
public:

    // int solve(int ind, int prev, vector<int>& nums, vector<vector<int>>& dp) {
    //     if(ind == nums.size()) {
    //         return 0;
    //     }
    //     if(dp[ind][prev+1] != -1) {
    //         return dp[ind][prev+1];
    //     }
    //     int len = solve(ind+1, prev, nums, dp);
    //     if(prev == -1 || nums[ind] > nums[prev]) {
    //         len = max(len, 1+ solve(ind+1, ind, nums, dp));
    //     }
    //     return dp[ind][prev+1] = len;
    // }

    int solution(int ind, int prev, int n, vector<int>& nums, vector<vector<int>>& dp) {
        if(ind == n) {
            return 0;
        }
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
        int len = solution(ind+1, prev, n, nums, dp);
        if(prev == -1 || nums[ind] > nums[prev]) {
            len = max(len, 1 + solution(ind+1, ind, n, nums, dp));
        }
        return dp[ind][prev+1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return solution(0, -1, nums.size(), nums, dp);
    }
};