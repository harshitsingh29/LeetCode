//leetcode link - https://leetcode.com/problems/deepest-leaves-sum/


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
    int deepestLeavesSum(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        while(!q.empty()) {
            sum = 0;
            int sz = q.size();
            for(int i = 1; i <= sz; i++) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if(node->left)q.push(node->left);
                if()q.push(node->right);
            }
        }
        return sum;
    }
};
