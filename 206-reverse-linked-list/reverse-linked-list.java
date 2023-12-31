/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode tempnode = null;
        while(head != null) {
            ListNode newhead = head;
            head = head.next;
            newhead.next = tempnode;
            tempnode = newhead;
            //System.out.println(tempnode.val);
        }
        System.gc();
        return tempnode;
    }
}