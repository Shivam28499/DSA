class MedianFinder
{
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (left.empty() || left.top() > num)
        {
            left.push(num);
        }
        else
        {
            right.push(num);
        }
        if (abs((int)left.size() - (int)right.size()) > 1)
        {
            right.push(left.top());
            left.pop();
        }
        else if (left.size() < right.size())
        {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian()
    {
        if (left.size() == right.size())
        {
            return (double)(left.top() + right.top()) / 2;
        }

        return left.top();
    }
};
