class Solution {
public:
    bool checkIfPangram(string s) {
        set<char>st;
        for(char it : s) {
            st.insert(it);
        }
        if(st.size() == 26) {
            return true;
        }
        return false;
    }
};