//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    {
        unordered_map<long long int, int> mp;
        int max_len = 0;
        long long int sum = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] == k) {
                max_len = max(max_len, 1);
            }
            sum += a[i];
            if(sum == k) {
                max_len = i + 1;
            }
            if(mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
            if(mp.find(sum-k) != mp.end()) {
                max_len = max(max_len, i - mp[sum-k]);
            }
            //cout<<max_len<<" ";
        }
        return max_len;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends