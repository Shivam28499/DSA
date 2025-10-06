class StockSpanner
{
public:
    stack<pair<int, int>> st;
    int i = 1;
    StockSpanner()
    {
    }

    int next(int price)
    {
        while (true)
        {
            int ans = 1;
            while (st.size() > 0 and st.top().first <= price)
                st.pop();
            if (st.size() == 0)
                ans = i;
            else
                ans = i - st.top().second;
            st.push({price, i++});
            return ans;
        }
    }
};