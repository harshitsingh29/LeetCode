class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n = nums.size();
        long long int sum = 0, ans = 0;
        unordered_map<int,int> mp;
        int ucount = 0;
        for(int i = 0; i < k-1; i++) {
            sum += nums[i];
            if(mp[nums[i]] == 0) {
                ucount++;
            }
            mp[nums[i]]++;
        }
        int j = 0;
        for(int i = k-1; i < n; i++) {
            sum += nums[i];
            if(mp[nums[i]] == 0) {
                //cout<<nums[i]<<1<<endl;
                ucount++;
            }
            mp[nums[i]]++;
            if(ucount >= m) {
                ans = max(ans, sum);
            }
            mp[nums[j]]--;
            sum -= nums[j];
            if(mp[nums[j]] == 0) {
                //cout<<nums[j]<<2<<endl;
                ucount--;
            }
            j++;
        }
        return ans;
    }
};