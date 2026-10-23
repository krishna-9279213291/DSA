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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)
            return head;
            
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* temp = head;
        ListNode* pretemp = dummy;
        
        while (temp != nullptr) {
            if (temp->val == val) {
                pretemp->next = temp->next;
                temp = temp->next;
            } else {
                pretemp = temp;
                temp = temp->next;
            }
        }
        
        return dummy->next;
    }
};