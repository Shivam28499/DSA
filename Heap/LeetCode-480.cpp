class Solution
{
public:
    int binarySearch(vector<int> &v, int num)
    {
        int low = 0;
        int high = v.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (num < v[mid])
                high = mid - 1;
            else if (num > v[mid])
                low = mid + 1;
            else
                return mid;
        }
        return low;
    }

    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        int size = nums.size();
        vector<double> median;
        vector<int> v(nums.begin(), nums.begin() + k);
        sort(v.begin(), v.end());
        int j = k, i = 0;
        if (k % 2 == 0)
        {
            median.push_back((double(v[k / 2]) + v[(k / 2) - 1]) / 2);
        }
        else
            median.push_back(v[k / 2]);

        while (j < size)
        {
            auto it = std::find(v.begin(), v.end(), nums[i]);
            v.erase(it);
            int ind = binarySearch(v, nums[j]);
            v.insert(v.begin() + ind, nums[j]);
            if (k % 2 == 0)
            {
                median.push_back((double(v[k / 2]) + v[(k / 2) - 1]) / 2);
            }
            else
                median.push_back(v[k / 2]);
            i++;
            j++;
        }
        return median;
    }
};