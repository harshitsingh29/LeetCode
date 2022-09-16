class Solution {
public:
    
    vector<vector<int>> dp;
    int findmax(vector<int>& num, int n, int k, int i, vector<int>& mul, int m) {
        if(k == m) {
            return 0;
        }
        if(dp[k][i] != INT_MIN) {
            return dp[k][i];
        }
        int maxans = INT_MIN;
        int p1 = num[i]*mul[k] + findmax(num, n, k+1, i+1, mul, m);
        int p2 = num[(n-1) - (k-i)]*mul[k] + findmax(num, n, k+1, i, mul, m);
        return dp[k][i] = max(p1, p2);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        int n = nums.size();
        int m = mul.size();
        dp.resize(m + 1, vector<int>(m + 1, INT_MIN));
        return findmax(nums, n, 0, 0, mul, m);
    }
};