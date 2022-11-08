class Solution {
public:
    string makeGood(string s) {
        vector<char>st;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            if(!st.empty() and abs(st.back() - s[i]) == 32) {
                st.pop_back();
            }
            else {
                st.push_back(s[i]);
            }
        }
        string res(st.begin(), st.end());
        return res;
    }
};