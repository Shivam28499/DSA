class Solution
{
public:
    vector<string> ans;
    void helper(TreeNode *root, string s)
    {
        if (!root)
        {
            return;
        }
        string p = to_string(root->val);
        if (!root->left and !root->right)
        {
            s = s + p;
            ans.push_back(s);
            return;
        }
        helper(root->left, s + p + "->");
        helper(root->right, s + p + "->");
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        string s = "";
        helper(root, s);
        return ans;
    }
};