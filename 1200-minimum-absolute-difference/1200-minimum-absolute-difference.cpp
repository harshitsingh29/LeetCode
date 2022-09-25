class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        map<int, vector<vector<int>>> mp;
        for(int i = 1; i < arr.size(); i++) {
            int a = arr[i] - arr[i-1];
            mp[a].push_back({arr[i-1], arr[i]});
        }
        vector<vector<int>> ans;
        for(auto it : mp) {
            ans = it.second;
            break;
        }
        return ans;
    }
};