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
    void pathSumutil(TreeNode* root,int sum, int sumsofar,vector<vector<int>>&ans, vector<int>ds) {
        if(!root) {
            return;
        }
        sumsofar += root->val;
        ds.push_back(root->val);
        if(!root->left and !root->right) {
            if(sumsofar == sum) {
                ans.push_back(ds);
            }
            return;
        }
        pathSumutil(root->left,sum,sumsofar,ans,ds);
        pathSumutil(root->right,sum,sumsofar,ans,ds); 
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>>ans;
        vector<int>ds;
        int sumsofar = 0;
        pathSumutil(root,sum,sumsofar,ans,ds);
        return ans;
    }
};