class Solution {
public:
    vector<vector<int>>result;
    unordered_set<int>vis;
    void helper(int src,int dest,vector<vector<int>>& graph,vector<int>& ans){
        if(src==dest){
            ans.push_back(src);
            result.push_back(ans);
            ans.pop_back();
        }
        vis.insert(src);
        ans.push_back(src);
        for(auto x : graph[src]){
            if(vis.find(x)==vis.end()){
                helper(x,dest,graph,ans);
            }
        }
        vis.erase(src);
        ans.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>ans;
        helper(0,n-1,graph,ans);
        return result;
    }
};