class Solution {
public:
    int maximum69Number (int num) {
        int n = log10(num);
        n++;
        vector<int> v;
        int i = 0;
        while(i < n) {
            v.push_back(num%10);
            num = num/10;
            i++;
        }
        int f = 0;
        int ans = 0;
        reverse(v.begin(), v.end());
        for(int i = 0; i < n; i++) {
            // cout<<v[i]<<" ";
            if(v[i] == 6 and f == 0) {
                v[i] = 9;
                f = 1;
            }
            ans*= 10;
            ans += v[i]; 
        }
        // cout<<endl;
        return ans;
    }
};