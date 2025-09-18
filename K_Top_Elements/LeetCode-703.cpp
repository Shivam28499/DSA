class KthLargest
{
public:
    vector<int> arr;
    int K;
    KthLargest(int k, vector<int> &nums)
    {
        arr = nums;
        sort(arr.begin(), arr.end());
        K = k;
    }

    int add(int val)
    {
        int lo = 0, hi = arr.size() - 1, mid;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (arr[mid] == val)
            {
                lo = mid;
                break;
            }
            else if (arr[mid] < val)
            {
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        arr.emplace(arr.begin() + lo, val);
        return arr[arr.size() - K];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */