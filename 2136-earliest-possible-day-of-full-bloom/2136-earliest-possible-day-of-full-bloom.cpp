class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int,int>> vp;
        for(int i = 0; i < n; i++) {
            vp.push_back({growTime[i], plantTime[i]});
        }
        sort(vp.begin(), vp.end());
        int res = 0;
        for(auto [p,q] : vp) {
            res = max(res, p) + q;
        }
        return res;
    }
};