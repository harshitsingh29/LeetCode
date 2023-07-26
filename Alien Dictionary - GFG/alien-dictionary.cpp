//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        for(int i = 0; i < N-1; i++) {
            string s = dict[i];
            string t = dict[i+1];
            for(int k = 0; k < min(s.length(), t.length()); k++) {
                if(s[k] != t[k]) {
                    adj[s[k] - '0' - 49].push_back(t[k] - '0' - 49);
                    //cout<<s[k] - '0' - 49<<" "<<t[k] - '0' - 49<<endl;
                    break;
                }
            }
        }
        queue<int> q;
        vector<int> in(K, 0);
        for(int i = 0; i < K; i++) {
            for(auto it : adj[i]) {
                in[it]++;
            }
        }
        for(int i = 0; i < K; i++) {
            if(in[i] == 0) {
                q.push(i);
            }
        }
        string ans = "";
        while(!q.empty()) {
            int k = q.front();
            q.pop();
            ans.push_back(k + 'a');
            for(auto it : adj[k]) {
                in[it]--;
                if(in[it] == 0) {
                    q.push(it);
                }
            }
        }
        //cout<<ans<<endl;
        if(ans.length() == K) {
            return ans;
        }
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends