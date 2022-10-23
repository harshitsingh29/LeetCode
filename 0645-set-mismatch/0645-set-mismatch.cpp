class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int> mp;
        vector<int> ans;
        for(int it : nums) {
            mp[it]++;
            if(mp[it] == 2) {
                ans.push_back(it);
            }
        }
        int i = 1;
        for(auto it : mp) {
            if(it.first != i) {
                ans.push_back(i);
                return ans;
            }
            else {
                i++;
            }
        }
        ans.push_back(i);
        return ans;
    } 
};