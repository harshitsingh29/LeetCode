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

    public int count = 0;

    public int countGoodNodes(TreeNode root, int k) {
        if(root == null) {
            return 0;
        }
        if(root.val >= k) {
            k = root.val;
            count++;
        }
        int a = countGoodNodes(root.left, k);
        int b = countGoodNodes(root.right, k);
        return count;
    }

    public int goodNodes(TreeNode root) {
        int k = Integer.MIN_VALUE;
        int t = countGoodNodes(root, k);
        return count;
    }
}