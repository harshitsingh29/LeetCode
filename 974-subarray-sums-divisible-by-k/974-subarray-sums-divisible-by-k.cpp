class Solution {
public:
    int subarraysDivByK(vector<int>& v, int k) {
        int n = v.size();
        unordered_map<long long int, int>mp;
        mp[0]=1;
        long long int ans = 0, sum = 0;
        for(int i = 0; i < n; i++) {
            sum += v[i];
            sum %= k;
            if(sum < 0) sum += k;
            ans += mp[sum];
            mp[sum]++;
        }
        return ans;
    }
};