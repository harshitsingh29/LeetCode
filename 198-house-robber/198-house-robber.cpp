class Solution {
public:
    
    int funutil(int ind, vector<int>& nums, vector<int>& dp) {
        if(ind >= nums.size()) {
            return 0;
        }
        if(dp[ind] != -1) {
            return dp[ind];
        }
        int maxi = 0;
        maxi = max(nums[ind] + funutil(ind+2, nums, dp), funutil(ind+1, nums, dp));
        return dp[ind] = maxi;
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return funutil(0, nums, dp);
    }
};