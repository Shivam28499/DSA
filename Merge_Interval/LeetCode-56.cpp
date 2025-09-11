class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            int a = ans[ans.size()-1][0];
            int b = ans[ans.size()-1][1];
            int c = intervals[i][0];
            int d = intervals[i][1];
            if(b>=c){
                ans.pop_back();
                int max_ = max(b,d);
                ans.push_back({a,max_});
            }else ans.push_back(intervals[i]);
        }
        return ans;
    }
};
