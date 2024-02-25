class Solution
{
    public:
        int trap(vector<int> &height)
        {
            int n = height.size();
            vector<int> maxl(n), maxr(n);
            maxl[0] = height[0];
            maxr[n - 1] = height[n - 1];
            for (int i = 1, j = n - 2; i < n && j >= 0; i++, j--)
            {
                maxl[i] = max(maxl[i - 1], height[i]);
                maxr[j] = max(maxr[j + 1], height[j]);
            }
            long long int ans = 0;
            for(int i = 0; i < n; i++) {
                ans += min(maxl[i], maxr[i]) - height[i];
            }
            return ans;
        }
};