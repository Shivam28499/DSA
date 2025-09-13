class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        if (!root)
            return {};
        queue<TreeNode *> qu;
        qu.push(root);
        vector<double> ans;
        while (!qu.empty())
        {
            int n = qu.size();
            double result = 0.0;
            for (int i = 1; i <= n; i++)
            {
                TreeNode *node = qu.front();
                qu.pop();
                result += node->val;
                if (node->left)
                    qu.push(node->left);
                if (node->right)
                    qu.push(node->right);
            }
            result = result / n;
            cout << result << " ";
            ans.push_back(result);
        }
        return ans;
    }
};