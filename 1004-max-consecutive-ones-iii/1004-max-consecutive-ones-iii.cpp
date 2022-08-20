class Solution {
public:
    int longestOnes(vector<int>& v, int k) {
        int n = v.size();
        int one = 0, zero = 0, l = 0, r = 0, ans = 0;
        while(r < n) {
            if(v[r]) {
                one++;
                r++;
            }
            else {
                zero++;
                r++;
            }
            
            while(zero > k) {
                if(v[l]) {
                    one--;
                    l++;
                }
                else {
                    zero--;
                    l++;
                }
            }
            ans = max(ans, one+zero);
        }
        return ans;
    }
};