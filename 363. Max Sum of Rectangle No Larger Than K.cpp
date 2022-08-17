class Solution {
public:
    
    int getmax(vector<int>& sum, int k) {
        int n = sum.size();
        int ans = 0, res = INT_MIN;
        for(int i = 0; i < n; i++) {
            ans = 0;
            for(int j = i; j < n; j++) {
                ans += sum[j];
                if(ans > res and ans <= k) {
                    res = ans;
                } 
            }
        }
        return res;
    }
    
    int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
        int r = mat.size(), c = mat[0].size();
        int curmax = INT_MIN;
        for(int i = 0; i < c; i++) {
            vector<int>sum(r,0);
            for(int j = i; j < c; j++) {
                for(int k = 0; k < r; k++) {
                    sum[k] += mat[k][j];
                }
                int maxval = getmax(sum,k);
                if(maxval == k) {
                    return maxval;
                }
                //cout<<maxval<<" ";
                if(maxval > curmax) {
                    curmax = maxval;
                }
            }
        }
        return curmax;
    }
};
