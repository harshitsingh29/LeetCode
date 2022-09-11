class Solution {
public:
    
    bool isP(int val, int steps, vector<int>& stones, int n, unordered_map<int, int>& mp, vector<vector<int>>& dp) {
        
        if(val == stones[n-1]) return dp[mp[val]][steps] = true;
        
        if(dp[mp[val]][steps] != -1) {
            if(dp[mp[val]][steps] == 1) {
                return true;
            }
            return false;
        }
        
        bool isPossible1 = false;
        bool isPossible2 = false;
        bool isPossible3 = false;
        
        
        if(steps - 1 > 0 and mp[val+steps-1] != 0) {
            isPossible1 = isP(val+steps-1, steps-1, stones, n, mp, dp);
        }
        
        if(mp[val+steps] != 0) {
            isPossible2 = isP(val+steps, steps, stones, n, mp, dp);
        }
        
        if(mp[val+steps+1] != 0) {
            isPossible3 = isP(val+steps+1, steps + 1, stones, n, mp, dp);
        }
        
        if(isPossible1 || isPossible2 || isPossible3) return dp[mp[val]][steps] = true;
        return dp[mp[val]][steps] = false;
    }
    
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(n < 2) return false;
        if(1 + stones[0] < stones[1]) return false;
        int pos = 1;
        int steps = 1;
        unordered_map<int, int>mp;
        for(int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }
        vector<vector<int>> dp(2001, vector<int>(2001,-1));
        return isP(stones[1], steps, stones, n, mp, dp);
    }
};