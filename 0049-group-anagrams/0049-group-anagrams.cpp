class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        unordered_map<string,vector <string>>mp;
        for(string it : s) {
            string t = it;
            sort(t.begin(), t.end());
            mp[t].push_back(it);
        }
        vector<vector<string>> v;
        for(auto it : mp)  {
            v.push_back(it.second);
        }
        return v;
    }
};