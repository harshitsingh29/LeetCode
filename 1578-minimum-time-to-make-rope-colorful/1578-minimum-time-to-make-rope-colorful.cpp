class Solution {
public:
    int minCost(string s, vector<int>& arr) {
        int n = s.size();
        int sum = 0;
        int res = 0;
        int maxi = 0, count = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            maxi = max(maxi, arr[i]);
            count++;
            if(i < n-1 and s[i] == s[i+1]) {
                continue;
            }
            else if(count > 1) {
                // cout<<sum<<" ";
                res += sum - maxi;
                maxi = 0;
                sum = 0;
                count = 0;
            }
            else {
                count = 0;
                sum = 0;
                maxi = 0;
            }
        }
        return res;
    }
};