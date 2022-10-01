class Solution {
public:
    
    int f(int i, string s, vector<int>& dp) {
        int n = s.length();
        if(i == n) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];
        int res = f(i+1, s, dp);
        if(i < n-1 and (s[i] == '1' || (s[i] == '2' and s[i+1] < '7'))) res += f(i+2,s,dp);
        return dp[i] = res;
    }
    
    int numDecodings(string s) {
        vector<int> dp(s.length(), -1);
        return s.empty() ? 0 : f(0,s,dp);
    }
};