class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int mid = 0;
        while(mid <= high) {
            switch(nums[mid]) {
                case 0:
                    swap(nums[mid], nums[low]);
                    mid++;
                    low++;
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[high], nums[mid]);
                    high--;
                    break;
            }
        }
    }
};