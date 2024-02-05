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
    public int res = 0, f;
    public void kutil(TreeNode root) {
        if(root == null){
            return;
        }
        kutil(root.left);
        f--;
        if(f == 0) {
            res = root.val;
            return;
        }
        kutil(root.right);
    }

    public int kthSmallest(TreeNode root, int k) {
        f = k;
        kutil(root);
        return res;
    }
}