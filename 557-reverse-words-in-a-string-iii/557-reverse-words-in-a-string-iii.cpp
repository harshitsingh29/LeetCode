class Solution {
public:
    string reverseWords(string s) {
        vector<string> w;
        string ans = "";
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != ' ') {
                ans += s[i];
            }
            if(i+1 == s.length() || s[i+1] == ' ') {
                reverse(ans.begin(), ans.end());
                w.push_back(ans);
                ans = "";
            }
        }
        string res = "";
        for(int i = 0; i < w.size(); i++) {
            if(i != w.size()-1) {
                res += w[i];
                res += " ";
            }
            else {
                res += w[i];
            }
        }
        return res;
    }
};