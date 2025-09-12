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

    ListNode *reverse(ListNode *head, int k, int length)
    {
        if (length < k)
            return head;
        ListNode *curr = head;
        ListNode *Next = head;
        ListNode *prev = NULL;
        int count = 1;
        while (count <= k and curr)
        {
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
            count++;
        }
        if (Next)
            head->next = reverse(Next, k, length - k);
        return prev;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int length = lengthOfList(head);
        return reverse(head, k, length);
    }
};