class Solution
{
public:
    int level(TreeNode *root)
    {
        if (!root)
            return 0;
        return 1 + max(level(root->left), level(root->right));
    }

    void helper(TreeNode *root, int &maxdia)
    {
        if (!root)
            return;
        int dia = level(root->left) + level(root->right);
        maxdia = max(maxdia, dia);
        helper(root->left, maxdia);
        helper(root->right, maxdia);
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        int maxdia = 0;
        helper(root, maxdia);
        return maxdia;
    }
};