class Solution
{
    public:

    //     int mergeSort(int low, int mid, int high, int n, vector<int> &nums)
    //     {
    //         //cout<<low<<" "<<mid<<" "<<high<<endl;
    //         int count = 0;
    //         int j = mid + 1;
    //         for (int i = low; i <= mid; i++)
    //         {
    //             while (j <= high && nums[i] > 2LL*nums[j])
    //             {
    //                 cout<<nums[i]<<" "<<i<<" "<<nums[j]<<" "<<j<<endl;
    //                 j++;
    //             }
    //             count += (j - (mid + 1));
    //         }
    //         vector<int> temp;
    //         int i = low;
    //         j = mid + 1;

    //         while (i <= mid && j <= high)
    //         {
    //             if (nums[i] <= nums[j])
    //             {
    //                 temp.push_back(nums[i]);
    //                 i++;
    //             }
    //             else
    //             {
    //                 temp.push_back(nums[j]);
    //                 j++;
    //             }
    //         }
    //         while (i <= mid)
    //         {
    //             temp.push_back(nums[i]);
    //             i++;
    //         }
    //         while (j <= high)
    //         {
    //             temp.push_back(nums[j]);
    //             j++;
    //         }
    //         for (int i = low; i <= high; i++)
    //         {
    //             nums[i] = temp[i - low];
    //         }
    //         return count;
    //     }

    // int merge(int low, int high, int n, vector<int> &nums)
    // {
    //     int count = 0;
    //     if (low < high)
    //     {
    //         int mid = (low + high) / 2;
    //         count += merge(low, mid, n, nums);
    //         count += merge(mid + 1, high, n, nums);
    //         count += mergeSort(low, mid, high, n, nums);
    //     }
    //     return count;
    // }

    // int reversePairs(vector<int> &nums)
    // {
    //     int n = nums.size();
    //     int low = 0;
    //     int high = n - 1;
    //     int count = merge(low, high, n, nums);
    //     return count;
    // }


    int merge(vector<int>& nums, int low, int mid, int high) {
        int count = 0;
        int j = mid + 1;
        
        for (int i = low; i <= mid; ++i) {
            while (j <= high && nums[i] > 2LL * nums[j]) {
                ++j;
            }
            count += j - (mid + 1);
        }
        
        vector<int> temp;
        int i = low, k = 0;
        j = mid + 1;
        
        while (i <= mid && j <= high) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }
        while (i <= mid) {
            temp.push_back(nums[i++]);
        }
        while (j <= high) {
            temp.push_back(nums[j++]);
        }
        
        for (int idx = low; idx <= high; ++idx) {
            nums[idx] = temp[k++];
        }
        
        return count;
    }
    
    int mergeSort(vector<int>& nums, int low, int high) {
        int count = 0;
        if (low < high) {
            int mid = low + (high - low) / 2;
            count += mergeSort(nums, low, mid);
            count += mergeSort(nums, mid + 1, high);
            count += merge(nums, low, mid, high);
        }
        return count;
    }
    
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};