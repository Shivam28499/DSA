class Solution {
public:
    set<vector<int>>st;
    vector<vector<int>>result;
    void helper(int i,vector<int> &nums,vector<int>& ans){
        if(i>=nums.size()){
            st.insert(ans);
            return;
        }
        helper(i+1,nums,ans);
        ans.push_back(nums[i]);
        helper(i+1,nums,ans);
        ans.pop_back();

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        helper(0,nums,ans);
        for(auto x:st) result.push_back(x);
        return result;
    }
};