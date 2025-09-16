class Solution
{
public:
    vector<TreeNode *> helper(int i, int n)
    {
        if (i <= 0 || i > n)
            return {NULL};
        vector<TreeNode *> result;
        for (int j = i; j <= n; j++)
        {
            vector<TreeNode *> l = helper(i, j - 1);
            vector<TreeNode *> r = helper(j + 1, n);
            for (auto x : l)
            {
                for (auto y : r)
                {
                    TreeNode *node = new TreeNode(j);
                    node->left = x;
                    node->right = y;
                    result.push_back(node);
                }
            }
        }
        return result;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        return helper(1, n);
    }
};