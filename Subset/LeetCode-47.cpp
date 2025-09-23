class Solution {
public:
    vector<vector<int>>result;
    set<vector<int>>st;
    void helper(int i,vector<int>& nums){
        if(i==nums.size()){
            st.insert(nums);
            return;
        }
        if(st.count(nums)) return;
        for(int idx=i;idx<nums.size();idx++){
            swap(nums[i],nums[idx]);
            helper(i+1,nums);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        helper(0,nums);
        for(auto x:st) result.push_back(x);
        return result;
    }
};