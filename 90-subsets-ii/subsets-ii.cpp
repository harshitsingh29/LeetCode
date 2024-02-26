class Solution {
public:
    
    void findsubset(int ind, vector<int>&ds, vector<vector<int>>&ans, vector<int>&nums, int n)
    {
        ans.push_back(ds);
        // for(int i = 0; i < ds.size(); i++) {
        //     cout<<ds[i]<<" ";
        // }
        // cout<<endl;
        for(int  i = ind; i < n; i++)
        {
            if(i!=ind and nums[i] == nums[i - 1]) continue;
            ds.push_back(nums[i]);
            findsubset(i + 1, ds, ans, nums, n);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int>ds;
        sort(nums.begin(),nums.end());
        findsubset(0, ds, ans, nums, n);
        return ans;
    }
};