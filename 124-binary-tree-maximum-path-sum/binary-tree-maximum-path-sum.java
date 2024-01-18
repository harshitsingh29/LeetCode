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
    public int max = Integer.MIN_VALUE;
    public int maxSum(TreeNode root) {
        if(root == null) {
            return 0;
        }
        int left = Math.max(0,maxSum(root.left));
        int right = Math.max(0,maxSum(root.right));
        max = Math.max(max, left + right + root.val);
        System.out.println(max);
        return Math.max(left, right) + root.val;
    }

    public int maxPathSum(TreeNode root) {
        //int max = Integer.MIN_VALUE;
        maxSum(root);
        return max;
    }
}