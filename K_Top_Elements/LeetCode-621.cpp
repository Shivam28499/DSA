class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<char, int> mp;
        for (auto x : tasks)
        {
            mp[x]++;
        }

        priority_queue<int> pq;
        for (auto x : mp)
        {
            pq.push(x.second);
        }

        int result = 0;
        while (!pq.empty())
        {
            vector<int> temp;
            for (int i = 1; i <= n + 1; i++)
            {
                if (!pq.empty())
                {
                    int p = pq.top();
                    pq.pop();
                    p--;
                    temp.push_back(p);
                }
            }
            for (auto f : temp)
            {
                if (f)
                    pq.push(f);
            }
            if (pq.empty())
                result += temp.size();
            else
                result += n + 1;
        }
        return result;
    }
};