/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int s = 0;
        ListNode* node = head;
        while(node != NULL) {
            s++;
            node = node->next;
        }
        if(n == s) {
            return head->next;
        }
        s -= n;
        n = 1;
        node = head;
        while(head != NULL) {
            if(s == n) {
                head->next = head->next->next;
                break;
            }
            n++;
            head = head->next;
        }
        return node;
    }
    
};