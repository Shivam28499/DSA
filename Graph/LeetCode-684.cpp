class Solution {
public:

    int find(int x,vector<int>& parent){
        if(x==parent[x]) return x;
        return find(parent[x],parent);
    }

    bool Union(int a,int b,vector<int>& parent,vector<int>& indegree){
        a = find(a,parent);
        b = find(b,parent);
        if(a==b) return true;
        if(indegree[a]>=indegree[b]){
            parent[a] = b;
            indegree[a]++;
        }else {
            parent[b] = a;
            indegree[b]++;
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>indegree(n+1,0);
        vector<int>parent(n+1,0);
        for(int i=0;i<=n;i++) parent[i] = i;

        for(int i=0;i<n;i++){
            int a = edges[i][0];
            int b = edges[i][1];
            bool ans = Union(a,b,parent,indegree);
            if(ans) return {a,b};
        }
        return {};
    }
};