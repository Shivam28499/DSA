class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        if (m == 0 and n == 0)
            return 0;
        int i = 0, j = 0, k = 0;
        vector<int> arr(n + m);
        while (i < m and j < n)
        {
            if (nums1[i] <= nums2[j])
            {
                arr[k] = nums1[i];
                i++;
            }
            else
            {
                arr[k] = nums2[j];
                j++;
            }
            k++;
        }
        if (i == m)
        {
            while (j < n)
            {
                arr[k] = nums2[j];
                k++;
                j++;
            }
        }

        if (j == n)
        {
            while (i < m)
            {
                arr[k] = nums1[i];
                k++;
                i++;
            }
        }

        for (int p = 0; p < m + n; p++)
            cout << arr[p] << "  ";

        if ((m + n) % 2 == 0)
        {
            double result = double((arr[(m + n) / 2] + arr[(m + n) / 2 - 1]) / 2.0);
            return result;
        }

        return double(arr[(m + n) / 2]);
    }
};