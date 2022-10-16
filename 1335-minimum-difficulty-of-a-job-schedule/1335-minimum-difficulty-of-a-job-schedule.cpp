class Solution {
public:
    
    int f(vector<int>& v, int d, int i, int n, vector<vector<int>>& dp) {
        if(d == 1) {
            int k = INT_MIN;
            for(int j = i; j < n; j++) {
                k = max(k, v[j]);
            }
            return k;
        }
        if(dp[i][d] != -1) return dp[i][d];
        else {
            int m = INT_MIN;
            int res = INT_MAX;
            for(int j = i; j < n-d+1; j++) {
                m = max(m, v[j]);
                res = min(res, m + f(v, d-1, j+1, n, dp));
            }
            return dp[i][d] = res;
        }
    }
    
    int minDifficulty(vector<int>& v, int d) {
        int n = v.size();
        if(d > n) return -1;
        vector<vector<int>> dp(n+1, vector<int>(d+1,-1));
        return f(v,d,0,n,dp);
    }
};

// int calc(vector<int>& jobDifficulty, int d , int start , int n)
//     {
//         if(d == 1)
//         {
//             int m = INT_MIN;
            
//             for(int i = start ; i < n ; i++)
//             {
//                 m = max(m , jobDifficulty[i]);
//             }
            
//             return m;
//         }
        
//         else
//         {
//             int m = INT_MIN;
//             int res = INT_MAX;
//             for(int i = start ; i < n - d + 1 ; i++)
//             {
//                 m = max(m , jobDifficulty[i]);
//                 res = min(res , m + calc(jobDifficulty , d - 1 , i + 1 , n));
//             }
            
//             return res;
//         }
//     }
    
//     int minDifficulty(vector<int>& jobDifficulty, int d)
//     {
//         int n = jobDifficulty.size();
//         if(n < d)
//             return -1;
        
//         else
//             return calc(jobDifficulty , d , 0 , n);
//     }
// };