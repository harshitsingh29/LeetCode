class Solution {
public:
    
    static bool comp(pair<int, string>& a, pair<int, string>& b) {
        if(a.first > b.first) return true;
        else if(a.first == b.first and a.second < b.second) return true;
        else {
            return false;
        }
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(auto it : words) {
            mp[it]++;
        }
        vector<pair<int, string>> vp;
        for(auto it : mp) {
            vp.push_back({it.second, it.first});
        }
        sort(vp.begin(), vp.end(), comp);
        vector<string> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(vp[i].second);
        }
        return ans;
    }
};