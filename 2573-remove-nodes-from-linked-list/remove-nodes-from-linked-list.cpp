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
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* ahead = NULL;
        while (curr != NULL) {
            ahead = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ahead;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        // Reverse Linked List

        head = reverseLinkedList(head);

        // Now remove every Node Smaller than current Node

        ListNode* curr = head;
        while (curr->next) {

            if (curr->next->val < curr->val) {
                curr->next = curr->next->next;
            } else
                curr = curr->next;
        }

        // Reverse the linked list again
        head = reverseLinkedList(head);

        // Return  the modified linked list

        return head;
    }
};