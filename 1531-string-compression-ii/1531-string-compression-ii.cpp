// class Solution {
// public:
    
//     // int ans = INT_MAX;
    
//     int f(int i, int j, int k, unordered_map<char, int>& mp, string& s, vector<vector<int>>& dp) {
//         if(j == k || i == s.length()) {
//             int res = 0;
//             for(auto it : mp) {
//                 if(it.second == 1) {
//                     res += 1;
//                 }
//                 else if(it.second > 1) {
//                     int t = log10(it.second) + 1;
//                     res += t + 1;
//                 }
//             }
//             return res;
//         }
//         if(j > k || i > s.length()) {
//             return 0;
//         }
//         if(dp[i][j] != -1) {
//             return dp[i][j];
//         }
//         mp[s[i]]--;
//         int ans1 = f(i+1, j+1, k, mp, s, dp);
//         mp[s[i]]++;
//         int ans2 = f(i+1, j, k, mp, s, dp);
//         return dp[i][j] = min(ans1, ans2);
        
//     }
     
//     int getLengthOfOptimalCompression(string s, int k) {
//         unordered_map<char, int> mp;
//         int n = s.length();
//         for(int i = 0; i < s.length(); i++) {
//             mp[s[i]]++;
//         }
//         vector<vector<int>> dp(101, vector<int>(101, -1));
//         f(0, 0, k, mp, s, dp);
//         for(int i = 0; i < k+1; i++) {
//             for(int j = 0; j < n; j++) {
//                 cout<<dp[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//         return 0;
//     }
// };


class Solution {
public:
    vector<vector<int>> dp;
    int find(int n){   // return the compressed length of 'n' similiar char
        if(n==1) return 1;
        else if(n>1 && n<10) return 2;
        else if(n>=10 && n<100) return 3;
        else return 4;
    }
    int dfs(string &s,int in,int k){
        if(k<0) return INT_MAX;
        if(in>=s.size() || (s.size()-in)<=k) return 0;
        if(dp[in][k]!=-1) return dp[in][k];
        
        int n = 0, t = 0,i = in;  char ch = s[in];  // n = no. of contigous same char after removing 't' char in-between.
        int re = dfs(s,in+1,k-1);  // Min length after removing current char from [in+1 to s.size()-1]
        
        for(; i<s.size() && t<=k;++i){
            if(s[i]==ch) n++;
            else re = min(re,find(n)+dfs(s,i,k-t++)); // check for subseq [i to s.size()]
        }
        if(t<=k) re = min(re,find(n)+dfs(s,i,k-t));
        return dp[in][k] = re;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        dp = vector<vector<int>>(s.size()+1,vector<int>(k+1,-1));
        return dfs(s,0,k);
    }
};