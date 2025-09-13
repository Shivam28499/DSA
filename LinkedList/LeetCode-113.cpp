class Solution
{
public:
    vector<vector<int>> result;
    void helper(TreeNode *root, int sum, vector<int> ans)
    {
        if (!root)
            return;
        if (sum - root->val == 0 and !root->left and !root->right)
        {
            ans.push_back(root->val);
            result.push_back(ans);
            return;
        }
        ans.push_back(root->val);
        helper(root->left, sum - root->val, ans);
        helper(root->right, sum - root->val, ans);
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> ans;
        helper(root, targetSum, ans);
        return result;
    }
};