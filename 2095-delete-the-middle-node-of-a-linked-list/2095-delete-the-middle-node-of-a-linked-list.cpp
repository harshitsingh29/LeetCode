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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL) {
            return NULL;
        }
        ListNode* ans = head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* even = head;
        int f = 0;
        while(fast->next != NULL and fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(f == 0) {
                f = 1;
            }
            else {
                even = even->next;
            }
        }
        if(fast->next == NULL) {
            even->next = even->next->next;
            cout<<even->val<<endl;
            return ans;
        }
        else {
            slow->next = slow->next->next;
            return ans;
        }
        
    }
};