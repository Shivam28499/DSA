class Solution
{
public:
    void helper(TreeNode *root, int sum, bool &ans)
    {
        if (!root)
            return;
        if (sum - root->val == 0 and !root->left and !root->right)
        {
            ans = true;
            return;
        }
        helper(root->left, sum - root->val, ans);
        helper(root->right, sum - root->val, ans);
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        bool ans = false;
        helper(root, targetSum, ans);
        return ans;
    }
};