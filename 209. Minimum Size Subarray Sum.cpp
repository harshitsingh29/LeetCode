class Solution {
public:
    int minSubArrayLen(int target, vector<int>& a) {
        int sum = 0;
        int j = 0, i = 0;
        int n = a.size();
        int max = INT_MAX;
        while(j < n) {
            if(sum + a[j] < target) {
                sum += a[j];
                j++;
            }
            else {
                sum += a[j];
                max = min(max, j - i + 1);
                while(sum >= target) {
                    sum -= a[i];
                    i++;
                    if(sum >= target) {
                        max = min(max, j - i + 1);
                    }
                }
                j++;
            }
        }
        return max == INT_MAX ? 0 : max;
    }
};
