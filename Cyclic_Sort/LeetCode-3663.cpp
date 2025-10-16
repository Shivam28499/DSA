class Solution
{
public:
    int getLeastFrequentDigit(int n)
    {
        vector<int> arr(10, 0);
        while (n > 0)
        {
            int rem = n % 10;
            arr[rem]++;
            n /= 10;
        }
        int ans = 0, count = INT_MAX;
        for (int i = 0; i < 10; i++)
        {
            if (arr[i] == 0)
                continue;
            if (arr[i] < count)
            {
                count = arr[i];
                ans = i;
            }
        }
        return ans;
    }
};