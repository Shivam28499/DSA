class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> st;
        vector<int> res(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > nums[n - 1])
            {
                res[n - 1] = nums[i];
                break;
            }
        }
        st.push(nums[n - 1]);
        for (int i = n - 2; i >= 0; i--)
        {
            while (st.size() > 0 and st.top() <= nums[i])
                st.pop();
            if (st.size() == 0)
            {
                for (int j = 0; j < n; j++)
                {
                    if (nums[j] > nums[i])
                    {
                        res[i] = nums[j];
                        break;
                    }
                }
            }
            else
                res[i] = st.top();
            st.push(nums[i]);
        }
        return res;
    }
};