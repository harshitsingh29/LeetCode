class Solution {
public:

    // static bool comp(pair<int,int>& a, pair<int, int>& b) {
    //     if(a.first < b.first) return true;
    //     return false;
    // }

    int minAbsoluteSumDiff(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = 1e9+7;
        long long sum = 0;
        vector<int>v,t;
        for(int i = 0; i < n; i++) {
            v.push_back(abs(a[i]-b[i]));
            sum += (abs(a[i]-b[i]) + m) % m;
        }
        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++) {
            int pos = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
            if(pos == 0) {
                t.push_back(abs(a[pos] - b[i]));
            }
            else if(pos == n) {
                t.push_back(abs(a[pos-1] - b[i]));
            }
            else {
                t.push_back(min(abs(a[pos-1] - b[i]), abs(a[pos] - b[i])));
            }
        }
        int ans = INT_MIN;
        for(int i = 0; i < n; i++) {
            ans = max(ans, v[i] - t[i]);
        }
        return (sum-ans+m)%m;
    }
};