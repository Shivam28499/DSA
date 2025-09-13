class Solution
{
public:
    void helper(TreeNode *root, long long &count, long long sum)
    {
        if (!root)
            return;
        if (sum - root->val == 0)
        {
            count++;
        }
        helper(root->left, count, sum - root->val);
        helper(root->right, count, sum - root->val);
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return 0;
        long long count = 0;
        helper(root, count, targetSum);
        count += pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
        return count;
    }
};