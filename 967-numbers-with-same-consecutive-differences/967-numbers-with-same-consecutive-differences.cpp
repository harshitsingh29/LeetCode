class Solution {
public:
    set<int> st;
    void find(int i, int num, int l, int n, int k) {
        if(l == n) {
            st.insert(num);
            return;
        }
        if(i + k <= 9 and i - k >= 0 and l + 1 <= n) {
            find(i+k, num*10 + (k+i), l+1, n, k);
            find(i-k, num*10 + (i-k), l+1, n, k);
        }
        else if(i + k <= 9 and l + 1 <= n) {
            find(i+k, num*10 + (k+i), l+1, n, k);
        }
        else if(i - k >= 0 and l + 1 <= n) {
            find(i-k, num*10 + (i-k), l+1, n, k);
        }
    }
    
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i = 1; i <= 9; i++) {
            if(i + k <= 9 and i - k >= 0) {
                long long int num = i;
                int l = 1;
                find(i,num,l,n,k);
            }
            else if(i + k <= 9) {
                long long int num = i;
                int l = 1;
                find(i,num,l,n,k);
            }
            else if(i - k >= 0){
                long long int num = i;
                int l = 1;
                find(i,num,l,n,k);
            } 
            else {
                continue;
            }
        }
        for(auto it : st) {
            ans.push_back(it);
        }
        return ans;
    }
};