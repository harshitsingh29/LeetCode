class Solution {
    
    int countsubmat(vector<int> sum, int n, int k) {
        int t = 0;
        int ans = 0;
        unordered_map<int,int>mp;
        for(int i = 0; i < n; i++) {
            t += sum[i];
            if(t == k) {
                ans++;
            }
            if(mp.find(t - k) != mp.end()) {
                ans += mp[t-k];
            }
            mp[t]++;
        }
        return ans;
    }
    
public:
    int numSubmatrixSumTarget(vector<vector<int>>& a, int k) {
        int n = a.size();
        int m = a[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++) {
            vector<int>sumr(n,0);
            for(int j = i; j < m; j++) {
                for(int k = 0; k < n; k++) {
                    sumr[k] += a[k][j];
                }
                ans += countsubmat(sumr,n,k);   
            }
        }
        return ans;
    }
};