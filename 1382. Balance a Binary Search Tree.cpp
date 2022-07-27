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
    
    TreeNode* balancedutil(vector<TreeNode*>& arr, int start, int end) {
        if(start > end) return NULL;
        int mid = (start + end) / 2;
        TreeNode* root = arr[mid];
        root->left = balancedutil(arr, start, mid-1);
        root->right = balancedutil(arr, mid+1, end);
        return root;
    }
    
    void inorderTraversal(TreeNode* root, vector<TreeNode*>& arr) {
        if(root == NULL) return;
        inorderTraversal(root->left, arr);
        arr.push_back(root);
        inorderTraversal(root->right, arr);
    }
    
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> arr;
        inorderTraversal(root, arr);
        return balancedutil(arr, 0, arr.size() - 1);
    }
};
