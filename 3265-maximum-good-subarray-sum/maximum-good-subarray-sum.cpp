class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        // long long ans = INT_MIN;
        // int n = nums.size();
        // for(int i = 0; i < n-1; i++) {
        //     for(int j = i+1; j < n; j++) {
        //         if(abs(nums[i]-nums[j]) == k) {
        //             long long sum = 0;
        //             for(int k = i; k <= j; k++) {
        //                 sum += nums[k];
        //             }
        //             ans = max(ans, sum);
        //         }
        //     }
        // }
        // return ans == INT_MIN ? 0 : ans;

        int n = nums.size();
        map<long long, long long> mp;
        long long sum = 0, ans = LONG_MIN;
        for(int i=0; i < n; i++) {
            sum += nums[i];
            long long k1 = nums[i] - k;
            long long k2 = nums[i] + k;
            if(mp.find(k1) != mp.end()) {
                long long temp = sum - (mp[k1] - k1);
                ans = max(ans, temp);
                // if(temp == ans) {
                //     cout<<1<<" "<<k2<<" "<<nums[i]<<endl;
                // }
            }
            if(mp.find(k2) != mp.end()) {
                long long temp = sum - (mp[k2] - k2);
                ans = max(ans, temp);
                // if(temp == ans) {
                //     cout<<2<<" "<<k2<<" "<<nums[i]<<endl;
                // }
            }


            if(mp.find(nums[i]) != mp.end()) {
                if(mp[nums[i]] > sum) {
                    mp[nums[i]] = sum;
                }
            }
            else {
                mp[nums[i]] = sum;
            }
        }
        return ans == LONG_MIN ? 0 : ans;
    }
};