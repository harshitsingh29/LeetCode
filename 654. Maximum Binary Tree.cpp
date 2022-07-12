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
    
    int findmax(vector<int> nums, int low, int high) {
        int maxval = INT_MIN;
        int idx = -1;
        for(int i = low; i <= high; i++) {
            if(nums[i] > maxval) {
                idx = i;
                maxval = nums[i];
            }
        }
        return idx;
    }
    
    TreeNode* funutil(vector<int>& nums, int low, int high) {
        if(low > high) {
            return NULL;
        }
        if(low == high) return new TreeNode(nums[low]);
        int idx = findmax(nums, low, high);
        TreeNode* root = new TreeNode(nums[idx]);
        root->left = funutil(nums, low, idx-1);
        root->right = funutil(nums, idx+1, high);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return funutil(nums, 0, nums.size()-1);
    }
};
