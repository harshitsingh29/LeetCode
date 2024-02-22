class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(),i;
        for(i = n-2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                break;
            }
        }
        if(i < 0) {
            reverse(nums.begin(), nums.end());
        }
        else {
            for(int k = n-1; k > i; k--) {
                if(nums[k] > nums[i]) {
                    swap(nums[k], nums[i]);
                    break;
                }
            }
            reverse(nums.begin()+i+1, nums.end());
        }
    }
};