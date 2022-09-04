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
    
    void countgoodNodes(TreeNode* root, int maxnode, int& count) {
        if(root == NULL) {
            return;
        }
        if(root->val >= maxnode) {
            count += 1;
            // cout<<root->val<<" ";
            countgoodNodes(root->left, root->val, count);
            countgoodNodes(root->right, root->val, count);
        } 
        else {
            countgoodNodes(root->left, maxnode, count);
            countgoodNodes(root->right, maxnode, count);
        }
    }
    
    int goodNodes(TreeNode* root) {
        int count = 0;
        int maxnode = root->val;
        countgoodNodes(root, maxnode, count);
        return count;
    }
};