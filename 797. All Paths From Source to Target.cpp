class Solution {
private: 
    void dfsutil(vector<vector<int>>& graph, vector<vector<int>>& allPath, vector<int> path, int targetnode, int curnode) {
        path.push_back(curnode);
        if(curnode ==targetnode) {
            allPath.push_back(path);
        }
        else {
            for(auto it : graph[curnode]) {
                dfsutil(graph, allPath, path, targetnode, it);
            }
        }
        path.pop_back();
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int targetnode = graph.size()-1;
        vector<int> path;
        vector<vector<int>> allPath;
        dfsutil(graph, allPath, path, targetnode, 0);
        return allPath;
    }
};
