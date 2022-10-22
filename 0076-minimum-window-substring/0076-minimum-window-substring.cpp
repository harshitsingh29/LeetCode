class Solution {
public:
        string minWindow(string s, string t) {
        if(s.size() == 0 || t.size() == 0 || (t.size() > s.size())) return "";
        // if(t.size() > s.size()) return ""
        unordered_map<char, int>mp;
        int count = t.size();
        for(int i = 0; i < t.length(); i++) mp[t[i]]++;
        int i = 0, start = 0, min = INT_MAX, left = 0;
        while(i <= s.size() and start < s.size()) {
            if(count) {
                if(i == s.size()) break;
                mp[s[i]]--;
                if(mp[s[i]] >= 0)  count--;
                i++;
            }
            else {
                if(i - start < min) {
                    min = i - start;
                    left = start;
                }
                mp[s[start]]++;
                if(mp[s[start]] > 0) count++;
                start++;
            }
        }
        return min == INT_MAX ? "" : s.substr(left,min);}
};