class Solution {
public:
    const int MOD = 1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> vpair;
        for(int i = 0; i < n; i++) {
            vpair.push_back({efficiency[i], speed[i]});
        }
        sort(vpair.rbegin(), vpair.rend());
        priority_queue<int, vector<int>, greater<int>>pq;
        long long int gsum = 0;
        long long int res = 0;
        for(auto& [x, y] : vpair) {
            // cout<<x<<" "<<y<<endl;
            pq.push(y);
            gsum += y;
            if(pq.size() > k) {
                gsum -= pq.top();
                pq.pop();
            }
            // cout<<res<<endl;
            res = max(res, gsum*x);
        }
        return res % MOD;
    }
};