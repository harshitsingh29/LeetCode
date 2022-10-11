class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;
        int a = INT_MAX;
        int b = a;
        for(auto it : nums) {
            if(it <= a) a = it;
            else if(it <= b) {
                b = it;
            }
            else {
                return true;
            }
        }
        return false;
    }
};