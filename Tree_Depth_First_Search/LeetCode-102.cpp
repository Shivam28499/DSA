class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        queue<TreeNode *> qu;
        qu.push(root);
        vector<vector<int>> result;
        while (!qu.empty())
        {
            int n = qu.size();
            vector<int> ans;
            for (int i = 1; i <= n; i++)
            {
                TreeNode *node = qu.front();
                qu.pop();
                ans.push_back(node->val);
                if (node->left)
                    qu.push(node->left);
                if (node->right)
                    qu.push(node->right);
            }
            result.push_back(ans);
        }
        return result;
    }
};