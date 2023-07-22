//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool dfs(int n, vector<int>& vis, vector<int>& path, vector<int> adj[]) {
        vis[n] = 1;
        path[n] = 1;
        for(auto it : adj[n]) {
            if(!vis[it]) {
                if(dfs(it, vis, path, adj)) {
                    return true;
                }
            }
            else if(path[it]) {
                return true;
            }
        }
        path[n] = 0;
        return false;
    }
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int n, vector<int> adj[]) {
        vector<int> vis(n,0), path(n,0);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                if(dfs(i, vis, path, adj)) {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends