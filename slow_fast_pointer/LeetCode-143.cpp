class Solution {
public:
    ListNode* Reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* Next = head;
        ListNode* prev = NULL;
        while(curr){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* b = Reverse(slow->next);
        slow->next = NULL;
        ListNode* a = head;
        ListNode* temp1 = a;
        ListNode* temp2 = b;
        while(a!=NULL and b!=NULL){
            temp1 = a->next;
            temp2 = b->next;
            a->next = b;
            a = temp1;
            if(a)b->next = a;
            b = temp2;
        }
        if(b) a->next = b;
   }
};