class Solution {
public:
    vector<vector<int>>result;
    void helper(int i,int n,int k,vector<int>&ans){
        if(ans.size()==k){
            result.push_back(ans);
            return;
        }
        if(i>n) return;
        for(int idx=i;idx<=n;idx++){
            ans.push_back(idx);
            helper(idx+1,n,k,ans);
            ans.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>ans;
        helper(1,n,k,ans);
        return result;
    }
};