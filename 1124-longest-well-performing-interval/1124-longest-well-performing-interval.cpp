class Solution {
public:
    int longestWPI(vector<int>& v) {
        int n = v.size();
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += v[i] > 8 ? 1 : -1;
            v[i] = sum;
        }
        unordered_map<int,int>ump;
        int maxlen = 0;
        for(int i = 0; i < n; i++) {
            if(v[i] > 0) {
                maxlen = i + 1;
            }
            if(ump.find(v[i]) == ump.end()) {
                ump[v[i]] = i;
            }
            if(ump.find(v[i] - 1) != ump.end()) {
                if(maxlen < i - ump[v[i]-1]) {
                    maxlen = i - ump[v[i]-1];
                }
            }
        }
        return maxlen;
   }
};