class Solution {
public:

    int solution(vector<int>& nums, int ind, vector<int>& dp) {
        if(ind >= nums.size()) {
            return 0;
        }
        if(dp[ind] != -1) {
            return dp[ind];
        }
        return dp[ind] = max(nums[ind] + solution(nums, ind+2, dp), solution(nums, ind+1, dp));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return solution(nums, 0, dp);
    }
};