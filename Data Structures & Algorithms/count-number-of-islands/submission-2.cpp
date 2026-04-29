class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>v(n, vector<bool>(m,false));
        int count= 0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(v[i][j]==false && grid[i][j]=='1'){
                    if(dfs(grid,v,n,m, i ,j)){
                        count++;
                    }
                }
            }
        }
        return count;
    }
    bool dfs(vector<vector<char>>& grid,vector<vector<bool>>&v, int n, int m , int i , int j){
        if(i<0||j<0||i>=n||j>=m||v[i][j]==true||grid[i][j]=='0'){
            return false;
        }
        v[i][j]=true;
         dfs(grid, v, n,m, i+1, j);
                dfs(grid, v, n,m, i-1, j);
                dfs(grid, v, n,m, i, j+1);
                dfs(grid, v, n,m, i, j-1);
                return true;

    }
};
