class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if(sum < x) {
            return -1;
        }
        sum -= x;
        int i = 0, j = 0, p = 0;
        int maxlen = INT_MIN;
        while(j < n) {
            p += nums[j];
            if(p < sum) {
                j++;
            }
            else if(p == sum) {
                maxlen = max(maxlen, j-i+1);
                j++;
            }
            else if(p > sum) {
                while(p > sum) {
                    p -= nums[i];
                    i++;
                }
                if(sum == p) {
                    maxlen = max(maxlen, j-i+1);
                }
                j++;
            }
        }
        if(maxlen == INT_MIN) return -1;
        else {
            return n - maxlen;
        }
    }
};