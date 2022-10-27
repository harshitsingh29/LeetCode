class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>>v1, v2;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(img1[i][j]) {
                    v1.push_back({i,j});
                }
                if(img2[i][j]) {
                    v2.push_back({i,j});
                }
            }
        }
        map<pair<int,int>,int>mp;
        int ans = 0;
        for(auto [x,y] : v1) {
            for(auto [a,b] : v2) {
                mp[{x-a,y-b}]++;
                ans = max(ans, mp[{x-a,y-b}]);
            }
        }
        return ans;
    }
};