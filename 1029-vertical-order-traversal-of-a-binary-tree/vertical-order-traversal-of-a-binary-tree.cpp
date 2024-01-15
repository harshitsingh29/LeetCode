/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    static bool comp(pair<int,int>& a, pair<int,int>& b) {
        if(a.second < b.second) {
            return true;
        }
        if(a.second == b.second) {
            return a.first < b.first;
        }
        else {
            return false;
        }
    }
    
    void traverse(TreeNode* root, int lvl, int ord, map<int, vector<pair<int,int>>>& mp) {
        if(root == NULL) {
            return;
        }
        mp[ord].push_back({root->val, lvl});
        traverse(root->left, lvl+1, ord-1, mp);
        traverse(root->right, lvl+1, ord+1, mp);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int,int>>> mp;
        traverse(root, 0, 0, mp);
        vector<vector<int>> ans;
        for(auto it : mp) {
            sort(it.second.begin(), it.second.end(), comp);
            vector<int> t;
            for(auto x : it.second) {
                t.push_back(x.first);
            }
            ans.push_back(t);
        }
        return ans;
    }
};