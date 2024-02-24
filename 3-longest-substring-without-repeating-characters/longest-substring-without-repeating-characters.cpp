class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int start = 0;
        int ans = 0;
        for(int i = 0; i < s.length(); i++) {
            start = max(start, mp[s[i]]);
            ans = max(ans, i-start+1);
            mp[s[i]] = i+1;
        }
        return ans;
    }
};