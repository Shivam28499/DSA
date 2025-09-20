class FreqStack
{
public:
    unordered_map<int, int> mp;
    priority_queue<pair<int, pair<int, int>>> pq;
    int pos = 0;
    FreqStack()
    {
    }

    void push(int val)
    {
        pq.push({++mp[val], {pos++, val}});
    }

    int pop()
    {
        auto val = pq.top();
        pq.pop();
        int x = val.second.second;
        mp[x]--;
        return x;
    }
};
