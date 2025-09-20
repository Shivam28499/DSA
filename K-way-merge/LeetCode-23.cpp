class cmp
{
public:
    bool operator()(const ListNode *l1, const ListNode *l2)
    {
        return l1->val > l2->val;
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
        int n = lists.size();
        for (int i = 0; i < n; i++)
        {
            if (lists[i] == NULL)
                continue;
            pq.push(lists[i]);
        }

        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;
        while (!pq.empty())
        {
            ListNode *curr = pq.top();
            pq.pop();
            if (curr->next)
                pq.push(curr->next);
            temp->next = curr;
            temp = temp->next;
        }
        return dummy->next;
    }
};