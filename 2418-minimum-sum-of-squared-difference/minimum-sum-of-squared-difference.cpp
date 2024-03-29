class Solution {
public:
    long long minSumSquareDiff(vector<int>& a, vector<int>& b, int p, int q) {
        long long sum = 0;
        int n = a.size();
        vector<long long> v(1e5+1);
        for(int i = 0; i < n; i++) {
            long long diff = abs(a[i] - b[i]);
            v[diff]++;
        }
        int k = p+q;
        for(int i = 1e5; i >= 1; i--) {
            int count = v[i];
            if(k > count) {
                v[i-1] += v[i];
                v[i] = 0;
                k -= count;
            }
            else {
                v[i] -= k;
                v[i-1] += k;
                k = 0;
                break;
            }
        }
        for(int i = 1; i <= 1e5; i++) {
            sum += (long long)v[i]*i*i;
        }
        return sum;
    }
};