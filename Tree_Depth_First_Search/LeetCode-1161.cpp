class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {
        queue<TreeNode *> qu;
        qu.push(root);
        int sum = INT_MIN, level = -1, count = 1;
        while (!qu.empty())
        {
            int n = qu.size();
            int ans = 0;
            for (int i = 1; i <= n; i++)
            {
                TreeNode *node = qu.front();
                qu.pop();
                ans += node->val;
                if (node->left)
                    qu.push(node->left);
                if (node->right)
                    qu.push(node->right);
            }

            if (ans > sum)
            {
                sum = ans;
                level = count;
            }
            count++;
        }
        return level;
    }
};