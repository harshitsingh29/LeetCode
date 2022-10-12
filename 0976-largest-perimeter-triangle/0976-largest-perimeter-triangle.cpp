class Solution {
public:
    int largestPerimeter(vector<int>& v) {
        sort(v.begin(), v.end());
        int n = v.size();
        int i = n-1;
        while(i >= 2) {
            if(v[i] < v[i-1] + v[i-2]) {
                return v[i] + v[i-1] + v[i-2];
            }
            else {
                i--;
            }
        }
        return 0;
    }
};