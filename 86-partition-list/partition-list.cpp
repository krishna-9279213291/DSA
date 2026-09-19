class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        // Dummy nodes
        ListNode* lessDummy = new ListNode(1);
        ListNode* greaterDummy = new ListNode(0);
        
        ListNode* less = lessDummy;
        ListNode* greater = greaterDummy;
        
        ListNode* curr = head;
        
        while (curr != nullptr) {
            
            if (curr->val < x) {
                less->next = curr;
                less = less->next;
            }
            else {
                greater->next = curr;
                greater = greater->next;
            }
            
            curr = curr->next;
        }
        
        // Greater list ka end null karo
        greater->next = nullptr;
        
        // Less list ko greater list se connect karo
        less->next = greaterDummy->next;
        
        return lessDummy->next;
    }
};