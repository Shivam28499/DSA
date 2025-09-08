class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n  = nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int p = j+1,q = n-1;
                while(p<q){
                    long long int sum = 0;
                    sum +=nums[i];
                    sum+=nums[j];
                    sum+=nums[p];
                    sum+=nums[q];
                    if(sum==target){
                        st.insert({nums[i],nums[j],nums[p],nums[q]});
                         q--;
                    }else if(sum>target){
                        q--;
                    }else p++;
                }
            }
        }
        vector<vector<int>>ans;
        for(auto x : st){
            ans.push_back(x);
        }
        return ans;
    }
};