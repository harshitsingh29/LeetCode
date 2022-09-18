class Solution {
public:
    
    int fun(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(nums.size(),0);
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0) dp[i] = nums[i];
            else if(i == 1) dp[i] = max(nums[i], nums[i-1]);
            else {
                dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
            }
        }
        return dp[n-1];
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> temp, temp2;
        for(int i = 0; i < nums.size(); i++) {
            if(i != 0) temp.push_back(nums[i]);
            if(i != nums.size()-1) temp2.push_back(nums[i]);
        }
        return max(fun(temp), fun(temp2));
    }
};