class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       ListNode* slow = head;
       ListNode* fast = head;
       bool flag = false;
       while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                flag = true;
                break;
            }
       } 
       if(flag==false) return NULL;
        ListNode* t = head;
        while(t!=slow){
            t=t->next;
            slow = slow->next;   
        }
        return t;
    }
};