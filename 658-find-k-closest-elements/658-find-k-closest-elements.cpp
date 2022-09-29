class Solution {
public:
    
    static bool comp(pair<int,int>& a, pair<int, int>& b) {
        if(a.first < b.first) return true;
        if(a.first == b.first and a.second < b.second) return true;
        
        return false;
    }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>> t;
        for(int i = 0; i < arr.size(); i++) {
            int f = abs(arr[i] - x);
            t.push_back({f,arr[i]});
        }
        sort(t.begin(), t.end(), comp);
        vector<int> res;
        for(int i = 0; i < k; i++) {
            res.push_back(t[i].second);
        }
        sort(res.begin(), res.end());
        return res;
    }
};