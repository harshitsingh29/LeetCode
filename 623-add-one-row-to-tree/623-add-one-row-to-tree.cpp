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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1) return new TreeNode(v, root, NULL);
        // int len;  
        queue<TreeNode*>q;
        q.push(root);
        while(--d) {
            // q.pop();
            int len = q.size();
            for(int i = 1; i <= len; i++) {
                if(d > 1) {
                    if((q.front()->left)) {
                        q.push(q.front()->left);
                    }
                    if((q.front()->right)) {
                        q.push(q.front()->right);
                    }
                }
                else {
                    q.front()->left = new TreeNode(v, q.front()->left, NULL);
                    q.front()->right = new TreeNode(v, NULL, q.front()->right);
                }
                q.pop();
            }
        }
        return root;
    }
};