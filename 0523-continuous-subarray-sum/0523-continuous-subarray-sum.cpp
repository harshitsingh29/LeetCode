class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() == 1) {
            return false;
        }
        map<int,int>mp;
        int rsum = 0;
        for(int i = 0; i < nums.size(); i++) {
            rsum += nums[i];
            rsum %= k;
            if(rsum == 0 and i > 0) {
                return true;
            }
            if(mp.find(rsum) != mp.end()) {
                if(i - mp[rsum] > 1) {
                    return true;
                }
            }
            else {
                mp[rsum] = i;
            }
        }
        return false;
    }
};