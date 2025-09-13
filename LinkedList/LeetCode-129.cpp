class Solution
{
public:
    int result = 0;
    void helper(TreeNode *root, int sum)
    {
        if (!root)
            return;
        if (!root->left and !root->right)
        {
            sum = sum * 10 + root->val;
            result += sum;
            return;
        }
        helper(root->left, sum * 10 + root->val);
        helper(root->right, sum * 10 + root->val);
    }
    int sumNumbers(TreeNode *root)
    {
        helper(root, 0);
        return result;
    }
};