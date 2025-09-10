class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            if(st.count(i)) continue;
            unordered_set<int>check;
            int j = i;
            bool forward = nums[i]>0;
            int prev = j;
            while(j<n){
                if(nums[j]>0 != forward) break;
                if(check.count(j)) return true;
                check.insert(j);
                st.insert(j);
                prev = j;
                j = ((j + nums[j]) % n + n) % n;
                if(prev==j) break;
            }
        }
        
        return false;
    }
};