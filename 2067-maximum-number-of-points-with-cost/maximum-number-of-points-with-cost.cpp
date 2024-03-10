class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        vector<long long> res ((int) points[0].size(), 0);
        for (auto i = 0; i < points.size(); i++) {
            for (auto j = 0; j < points[i].size(); j++) {
                res[j] += points[i][j]; // Here, res[j] is the total points we have if we pick the j-th number in the i-th row.
                if (j > 0) res[j] = max (res[j], res[j - 1] - 1); // Here, we prepare vector res for the next row's points
                //cout<<res[j]<<" ";
            }
            //cout<<endl;
            for (int j = points[i].size() - 2; j >= 0; j--){
                res[j] = max (res[j], res[j + 1] - 1); 
                cout<<res[j]<<" ";
            }
                
            //cout<<endl;
        }
        return *max_element(res.begin(), res.end());
    }
};