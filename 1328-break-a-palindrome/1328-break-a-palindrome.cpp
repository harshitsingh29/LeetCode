class Solution {
public:
    string breakPalindrome(string str) {
        int n = str.length();
        if(n == 1) return "";
        else {
            for(int i = 0; i < n; i++) {
                char ch = str[i];
                str[i] = 'a';
                if(str[i] != str[n-i-1]) return str;
                else {
                    str[i] = ch;
                }
            }
            str[n-1] = 'b';
            return str;
            
        }
    }
};