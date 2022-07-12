/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:

    int funutil(TreeNode* current, TreeNode* parent, TreeNode* grandP) {
        int sum = 0;
        if(current == NULL) return 0;
        if(grandP != NULL and grandP->val % 2 == 0) {
            sum += current->val;
        }
        sum += funutil(current->left, current, parent);
        sum += funutil(current->right, current, parent);
        return sum;
    }

    int sumEvenGrandparent(TreeNode *root)
    {
        return funutil(root, NULL, NULL);
    }
};
