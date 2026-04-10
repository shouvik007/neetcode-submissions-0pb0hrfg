class Solution {
public:
    void dfs(int n , int m , vector<vector<bool>>& visited, int i , int j, vector<vector<char>>& grid) {
        if(i<0||j<0||i>=n||j>=m||grid[i][j]=='0'||visited[i][j]) {
            return ;
        }
        visited[i][j]=true;
        dfs(n,m , visited, i+1,j,grid);
        dfs(n,m , visited, i-1,j,grid);
        dfs(n,m , visited, i,j+1,grid);
        dfs(n,m , visited, i,j-1,grid);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()){
            return 0;
        }
        int n = grid.size();
        int m = grid[0].size();
        int count =0;
        vector<vector<bool>>visited(n, vector<bool>(m,false));
        for(int i =0 ;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]=='1'&&visited[i][j]==false){
                    dfs(n , m ,visited, i, j, grid );
                    count++;
                }
            }
        }
        return count;
    }
};
