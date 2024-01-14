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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        if(root == null) {
            return ans;
        }
        Queue<TreeNode> q = new LinkedList();
        q.add(root);
        int f = 0;
        while(!q.isEmpty()) {
            int len = q.size();
            List<Integer> res = new ArrayList<>();
            f++;
            while(len-- > 0) {
                TreeNode temp = q.peek();
                q.poll();
                res.add(temp.val);
                if(temp.left != null) q.add(temp.left);
                if(temp.right != null) q.add(temp.right);
            }
            if(f%2==0) {
                Collections.reverse(res);
            }
            ans.add(res);
        }
        return ans;
    }
}