class Solution {
public:
    vector<vector<int>>result;
    void helper(int i,vector<int>& can,int sum,int target,vector<int>&ans){
        if(sum==target){
            result.push_back(ans);
            return;
        }
        if(target<sum) return;
        if(i>=can.size()) return; 
        for(int j=i;j<can.size();j++){
            if(target>=sum){
                ans.push_back(can[j]);
                helper(j,can,sum + can[j],target,ans);
                ans.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        vector<int>ans;
        helper(0,can,0,target,ans);
        return result;
    }
};