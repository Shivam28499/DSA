class Solution
{
public:
    int maximumSum(vector<int> &arr)
    {
        int n = arr.size();
        int nodel = arr[0];
        int onedel = INT_MIN;
        int maxi = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (onedel != INT_MIN)
            {
                onedel = max(onedel + arr[i], nodel);
            }
            else
                onedel = nodel;
            nodel = max(arr[i], nodel + arr[i]);
            maxi = max({maxi, nodel, onedel});
        }
        return maxi;
    }
};