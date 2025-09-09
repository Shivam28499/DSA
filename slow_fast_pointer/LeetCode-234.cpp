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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next and fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = Reverse(slow->next);
        ListNode* temp = head;
        while(slow){
            cout<<temp->val<<" "<<slow->val<<endl;
            if(slow->val!=temp->val) return false;
            slow = slow->next;
            temp = temp->next;
        }
        return true;
    }
};