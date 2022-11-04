class Solution {
public:
    string reverseVowels(string s) {
        
        vector<char> t;
        
        for(int it = 0; it < s.length(); it++) {
            if(s[it] == 'a' || s[it] == 'e' || s[it] == 'i' || s[it] == 'o' || s[it] == 'u' || s[it] == 'A' || s[it] == 'E' || s[it] == 'I' || s[it] == 'O' || s[it] == 'U') {
                t.push_back(s[it]);
            }
        }
        
        for(int it = 0; it < s.length(); it++) {
            if(s[it] == 'a' || s[it] == 'e' || s[it] == 'i' || s[it] == 'o' || s[it] == 'u' || s[it] == 'A' || s[it] == 'E' || s[it] == 'I' || s[it] == 'O' || s[it] == 'U') {
                char q = t.back();
                s[it] = q;
                t.pop_back();
            }
        }
        
        return s;
    }
};