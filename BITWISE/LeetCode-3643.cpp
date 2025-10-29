class Solution
{
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>> &grid, int x, int y, int k)
    {
        int i = x, z = y, j = x + k - 1;
        while (i < j)
        {
            while (z < y + k)
            {
                swap(grid[i][z], grid[j][z]);
                z++;
            }
            z = y;
            i++, j--;
        }
        return grid;
    }
};