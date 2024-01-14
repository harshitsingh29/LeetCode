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
    
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(p == null && q == null) {
            return true;
        }
        if(p == null || q == null || p.val != q.val) {
            return false;
        }
        return (isSameTree(p.left,q.left) && isSameTree(p.right, q.right));
    }

    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        if(root == null) {
            return false;
        }
        // if(root.val != subRoot.val) {
        //     boolean left = isSubtree(root.left, subRoot);
        //     boolean right = isSubtree(root.right, subRoot);
        //     return left || right;
        // }
        // else {
        //     boolean ans = isSameTree(root, subRoot);
        //     if(ans == true) {
        //         return true;
        //     }
        //     else {
        //         boolean left = isSubtree(root.left, subRoot);
        //         boolean right = isSubtree(root.right, subRoot);
        //         return left || right;
        //     }
        // }

        if(isSameTree(root, subRoot)) {
            return true;
        }
        else {
            return isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);
        }


    }
}