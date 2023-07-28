//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
    void dfstopo(int node, int vis[], vector<pair<int,int>> adj[], stack<int>& st) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            int v = it.first;
            if(!vis[v]) {
                dfstopo(v, vis, adj, st);
            }
        }
        st.push(node);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[N];
        for(int i = 0; i < M; i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            int c = edges[i][2];
            adj[a].push_back({b,c});
        }
        int vis[N] = {0};
        stack<int> st;
        for(int i = 0; i < N; i++) {
            if(!vis[i]) {
                dfstopo(i, vis, adj, st);
            }
        }
        // queue<int>q;
        // for(int i = 0; i < N; i++) {
        //     if(in[i] == 0) {
        //         q.push(i);
        //     }
        // }
        // stack<int> st;
        // while(!q.empty()) {
        //     int k = q.front();
        //     q.pop();
        //     st.push(k);
        //     //cout<<k<<" ";
        //     for(auto it : adj[k]) {
        //         in[it.first]--;
        //         if(in[it.first] == 0) {
        //             q.push(it.first);
        //         }
        //     }
        // }
        vector<int> dist(N);
        for(int i = 0; i < N; i++) {
            dist[i] = 1e9;
        }
        dist[0] = 0;
        while(!st.empty()) {
            int k = st.top();
            st.pop();
            for(auto it : adj[k]) {
                int v = it.first;
                int wt = it.second;
                if(dist[k] + wt < dist[v]) {
                    dist[v] = dist[k] + wt;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            if (dist[i] == 1e9) dist[i] = -1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends