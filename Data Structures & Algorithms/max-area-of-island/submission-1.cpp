class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i , int j, int n , int m , vector<vector<bool>>& vis,int count){
        if(i<0||j<0||i>=n||j>=m||vis[i][j]==true||grid[i][j]==0){
            return 0;
        }
        count = count+1;
        vis[i][j]=true;
        int left = dfs(grid,i,j-1,n,m,vis,count );
        int right =dfs(grid,i,j+1,n,m,vis,count );
        int up =dfs(grid,i+1,j,n,m,vis,count );
        int down =dfs(grid,i-1,j,n,m,vis,count );
        return  (left+right+down+up)+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n =grid.size();
        int m = grid[0].size();
        int maxcount = 0;
        vector<vector<bool>>vis(n, vector<bool>(m,false));
        for(int i =0;i<n;i++){
            
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&grid[i][j]==1) {
                    int count= dfs(grid,i,j,n,m,vis,0);
                     maxcount = max(count, maxcount);
                }
               
            }
            
        }
        return maxcount;
    }
};
