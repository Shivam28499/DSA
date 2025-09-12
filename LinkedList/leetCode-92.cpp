class Solution
{
public:
    ListNode *Reverse(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *Next = head;
        ListNode *prev = NULL;
        while (curr)
        {
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;
        if (!head || !head->next)
            return head;
        ListNode *a = NULL;
        ListNode *b = NULL;
        ListNode *c = NULL;
        ListNode *d = NULL;
        ListNode *temp = head;
        int n = 1;
        while (temp)
        {
            if (n == left - 1)
                a = temp;
            if (n == left)
                b = temp;
            if (n == right)
                c = temp;
            if (n == right + 1)
                d = temp;
            temp = temp->next;
            n++;
        }
        if (a)
            a->next = NULL;
        c->next = NULL;
        c = Reverse(b);
        if (a)
            a->next = c;
        b->next = d;
        if (a)
            return head;
        return c;
    }
};