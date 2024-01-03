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
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> pq = new PriorityQueue<>((a,b)->a.val - b.val);
        for(int i = 0; i < lists.length; i++) {
            ListNode x = lists[i];
            while(x!=null) {
                pq.add(x);
                x=x.next;
            }
        }
        ListNode ans = pq.poll();
        ListNode temp = ans;
        while(!pq.isEmpty()) {
            temp.next=pq.poll();
            temp=temp.next;
        }
        if(temp!=null) {
            temp.next=null;
        }
        return ans;
    }
}