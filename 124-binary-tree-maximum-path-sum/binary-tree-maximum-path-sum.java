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
    public int maxi = Integer.MIN_VALUE;
    public int maxSum(TreeNode root, int max) {
        if(root == null) {
            return 0;
        }
        int left = Math.max(0,maxSum(root.left, max));
        int right = Math.max(0,maxSum(root.right, max));
        maxi = Math.max(maxi, left + right + root.val);
        System.out.println(maxi);
        return Math.max(left, right) + root.val;
    }

    public int maxPathSum(TreeNode root) {
        int max = Integer.MIN_VALUE;
        int k = maxSum(root, max);
        return maxi;
    }
}