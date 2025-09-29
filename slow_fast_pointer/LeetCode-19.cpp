class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head || !head->next)
            return NULL;
        ListNode *temp = head;
        int size = 0;
        while (temp)
        {
            temp = temp->next;
            size++;
        }
        if (n > size)
            return head;
        if (size == n)
            return head->next;
        size = size - n;
        temp = head;
        for (int i = 1; i < size; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};