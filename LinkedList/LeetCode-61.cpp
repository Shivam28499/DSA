class Solution
{
public:
    int lengthOfList(ListNode *head)
    {
        ListNode *temp = head;
        int count = 0;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode *rotateRight(ListNode *head, int k)
    {
        int length = lengthOfList(head);
        if (!head || !head->next)
            return head;
        k = k % length;
        ListNode *temp = head;
        ListNode *a = NULL;
        ListNode *b = NULL;
        ListNode *c = NULL;
        for (int i = 1; i <= length; i++)
        {
            if (i == length - k)
                a = temp;
            if (i == length - k + 1)
                b = temp;
            if (i == length)
                c = temp;
            temp = temp->next;
        }
        if (a)
            a->next = NULL;
        if (b)
            c->next = head;
        if (!b)
            return head;
        return b;
    }
};