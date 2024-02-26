class Solution {
public:

    set<vector<int>> st;
    void fun(int i, vector<int>ans, int n, vector<int>& nums) {
        if(i == n) {
            sort(ans.begin(), ans.end());
            st.insert(ans);
            return;
        }
        ans.push_back(nums[i]);
        fun(i+1,ans,n,nums);
        ans.pop_back();
        fun(i+1,ans,n,nums);
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ans;
        vector<vector<int>> res;
        fun(0,ans,nums.size(),nums);
        for(auto it : st) {
            res.push_back(it);
        }
        return res;
    }
};