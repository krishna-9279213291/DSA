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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *t1=list1,*t2=list2;
        vector<int> arr;
        if(list1==NULL) return list2;
        if (list2==NULL) return list1;
        while(t1!=NULL && t2!=NULL){
            if((t1->val) <= (t2->val)){
               arr.push_back(t1->val);
               t1=t1->next;
            }else{
              arr.push_back(t2->val);
              t2=t2->next;
            }
        }
        while(t1!=NULL){
            arr.push_back(t1->val);
            t1=t1->next;
        }
        while(t2!=NULL){
            arr.push_back(t2->val);
            t2=t2->next;
        }
        
        ListNode *head=new ListNode(arr[0]);
         ListNode *temp=head;
        for(int i=1;i<arr.size();i++){
            ListNode *newNode=new ListNode(arr[i]);
            temp->next=newNode;
            temp=newNode;
        }
        return head;
    }
};