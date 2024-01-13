/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean ans = true;
    public int cal(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int left = cal(root.left);
        int right = cal(root.right);
        if(Math.abs(left-right) > 1) {
            ans = false;
        }
        return Math.max(left,right)+1;
    }

    public boolean isBalanced(TreeNode root) {
        int val = cal(root);
        return ans;
    }
}