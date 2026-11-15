class Solution {
    // Find the middle node of the linked list
    ListNode* findmid(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Merge two sorted linked lists
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummy(-1);
        ListNode* temp = &dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }

        // Attach the remaining nodes
        if (list1) temp->next = list1;
        else temp->next = list2;

        return dummy.next;
    }

public:
    ListNode* sortList(ListNode* head) {
        // Base case: zero or one node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Divide the list into two halves
        ListNode* mid = findmid(head);
        ListNode* rightHead = mid->next;
        mid->next = nullptr;

        // Recursively sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHead);

        // Merge the sorted halves
        return merge(left, right);
    }
};