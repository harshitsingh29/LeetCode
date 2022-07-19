class Solution
{
    public:
        int maximumSum(vector<int> &nums)
        {
            int n = nums.size();
            vector<pair<int, int>> v;
            for (int i = 0; i < n; i++)
            {
                int temp = nums[i], sum = 0;
                while (temp > 0)
                {
                    sum += temp % 10;
                    temp /= 10;
                }
                v.push_back({ sum,
                    nums[i] });
            }
            sort(v.begin(), v.end());
            int res = -1;
            for (int i = 0; i < v.size() - 1; i++)
            {
                if (v[i].first == v[i + 1].first)
                {
                    res = max(res, v[i].second + v[i + 1].second);
                }
            }
            return res;
        }
};
