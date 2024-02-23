class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size() < 4) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-3; i++) {
            for(int j = i+1; j < nums.size()-2; j++) {
                long long diff = target - (static_cast<long long>(nums[i]) + static_cast<long long>(nums[j]));
                int low = j+1;
                int high = nums.size()-1;
                while(low < high) {
                    if(nums[low] + nums[high] == diff) {
                        int temp = nums[low];
                        int temp1 = nums[high];
                        ans.push_back({nums[i], nums[j], nums[low], nums[high]});
                        while(nums[low] == temp and low < high) {
                            low++;
                        }
                        while(nums[high] == temp1 and low < high) {
                            high--;
                        }
                    }
                    else if(nums[low] + nums[high] > diff) {
                        high--;
                    }
                    else {
                        low++;
                    }
                }  
                while(j < nums.size()-1 and nums[j] == nums[j+1]) {
                    j++;
                } 
            }
            while(i < nums.size()-1 and nums[i] == nums[i+1]) {
                i++;
            } 
        }
        return ans;
    }
};