class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& fL, vector<vector<int>>& sL) {
        int m = fL.size();
        int n = sL.size();
        if(m==0 || n==0) return {};
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            fL.push_back(sL[i]);
        }
        sort(fL.begin(),fL.end());
        pair<int,int>pp;
        pp = {fL[0][0],fL[0][1]};
        for(int i=1;i<m+n;i++){
            int a = fL[i][0];
            int b = fL[i][1];
            if(pp.second>=a){
                ans.push_back({max(pp.first,a),min(pp.second,b)});
                pp = {min(pp.first,a),max(pp.second,b)};
            }else pp = {a,b};
        }
        return ans;
    }
};