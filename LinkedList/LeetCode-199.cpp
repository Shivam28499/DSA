class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        if (!root)
            return {};
        queue<TreeNode *> qu;
        qu.push(root);
        vector<int> ans;
        while (!qu.empty())
        {
            int n = qu.size();
            for (int i = 1; i <= n; i++)
            {
                TreeNode *node = qu.front();
                qu.pop();
                if (i == n)
                    ans.push_back(node->val);
                if (node->left)
                    qu.push(node->left);
                if (node->right)
                    qu.push(node->right);
            }
        }
        return ans;
    }
};