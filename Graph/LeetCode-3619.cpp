class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<int>>&vis,int row,int col,long long& sum){
        int m  = grid.size();
        int n = grid[0].size();
        vis[row][col] = 1;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        sum += grid[row][col];
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 and ncol<n && vis[nrow][ncol]==0 && grid[nrow][ncol]){
                dfs(grid,vis,nrow,ncol,sum);
            }
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m  = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 and grid[i][j]){
                    long long sum = 0;
                    dfs(grid,vis,i,j,sum);
                    if(sum%k==0) ans++;  
                }
            }
        }
        return ans;
    }
};