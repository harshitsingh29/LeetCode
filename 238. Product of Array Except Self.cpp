class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int n = nums.size();
        // vector<pair<int,int>>f(n);
        // f[0].first = 1;
        // for(int i = 1; i < n; i++) {
        //     f[i].first = f[i-1].first * nums[i-1];
        // }
        // f[n-1].second = 1;
        // for(int i = n-2; i >= 0; i--) {
        //     f[i].second = f[i+1].second * nums[i+1];
        // }
        // for(int i = 0; i < n; i++) {
        //     nums[i] = f[i].first * f[i].second;
        // }
        // return nums;
        
        
        int n = nums.size();
        int post = 1, pre = 1;
        vector<int>res(n);
        for(int i = 0; i < n; i++) {
            res[i] = pre;
            pre *= nums[i];
        }
        for(int i = n-1; i>=0; i--) {
            res[i] *= post;
            post *= nums[i];
        }
        return res;
        
    }
};
