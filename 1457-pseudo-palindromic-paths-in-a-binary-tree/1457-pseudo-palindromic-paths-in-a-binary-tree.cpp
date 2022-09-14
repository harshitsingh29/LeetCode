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
    map<int,int>mp;
    int ans = 0;
    
    bool checkPal() {
        int count = 0;
        for(auto it : mp) {
            if(it.second % 2 == 1) {
                count++;
            }
        }
        return count <= 1;
    }
    
    void countPal(TreeNode* root) {
        if(root == NULL) {
            return;
        } 
        mp[root->val]++;
        if(root->left == NULL and root->right == NULL) {
            if(checkPal()) {
                ans++;
            }
        }
        countPal(root->left);
        countPal(root->right);
        mp[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        countPal(root);
        return ans;
    }
};