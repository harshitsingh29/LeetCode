class Solution
{
    public:

        vector<vector < int>> ans;

    void fun(int ind, int t, vector<int> &ds, vector<int> &arr)
    {
        if (ind == arr.size())
        {
            if (t == 0)
            {
                ans.push_back(ds);
            }
            return;
        }
        if (arr[ind] <= t)
        {
            ds.push_back(arr[ind]);
            fun(ind, t - arr[ind], ds, arr);
            ds.pop_back();
        }
        fun(ind + 1, t, ds, arr);
    }

    vector<vector < int>> combinationSum(vector<int> &arr, int target)
    {
        vector<int> ds;
        fun(0, target, ds, arr);
        return ans;
    }
};