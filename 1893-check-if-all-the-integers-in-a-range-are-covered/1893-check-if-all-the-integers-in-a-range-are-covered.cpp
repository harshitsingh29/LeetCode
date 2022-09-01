class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        for(int i = left; i <= right; i++) {
            int x = i;
            int f = 0;
            for(auto it : ranges) {
                if(i >= it[0] and i <= it[1]) {
                    f = 1;
                }
            }
            if(!f) {
                return false;
            }
        }
        return true;
    }
};