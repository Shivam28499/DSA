class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int lo = 0, hi = letters.size() - 1;
        char ch = '0';
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (letters[mid] <= target)
            {
                lo = mid + 1;
            }
            else if (letters[mid] > target)
            {
                hi = mid - 1;
                ch = letters[mid];
            }
        }
        return ch == '0' ? letters[0] : ch;
    }
};