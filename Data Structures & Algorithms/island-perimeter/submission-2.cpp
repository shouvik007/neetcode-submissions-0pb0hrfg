class Solution {
public:
    int count = 0;
    int dfs(int i , int j , int n , int m , vector<vector<int>>& grid, vector<vector<bool>>&v) {
        if(i<0||j<0||i>=n||j>=m||grid[i][j]== 0){
            return 1;
        }
        if(v[i][j]==true){
            return 0;
        }
        v[i][j]=true;
        return dfs(i+1,j,n,m,grid,v)+
            dfs(i,j+1,n,m,grid,v)+
            dfs(i-1,j,n,m,grid,v)+
            dfs(i,j-1,n,m,grid,v);

    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>v(n,vector<bool>(m,false));
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return dfs(i,j,n,m,grid,v);
                }
            }
        }
        return 0;
    }
};