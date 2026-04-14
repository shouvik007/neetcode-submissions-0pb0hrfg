class Solution {
public:
    
       int INF = 2147483647 ;
    // int dfs(vector<vector<int>>& grid,int i , int j ,vector<vector<bool>>& vis){
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     if(i<0||j<0||i>=n||j>=m||vis[i][j]||grid[i][j]==-1){
    //         return INF ;
    //     }
    //     if (grid[i][j] == 0) {
    //         return 0;
    //     }
    //     int res = INF;
    //     vis[i][j]= true;
    //     int left = dfs(grid, i,j-1, vis);
    //     if(left!=INF) {
    //         res = min(res, 1+left);
    //     }
    //     int right = dfs(grid,i, j+1, vis); 
    //     if(right != INF) {
    //         res = min(res, 1+right);
    //     }
    //     int up =  dfs(grid,i+1, j, vis);
    //     if(up != INF) {
    //         res = min(res, 1+up);
    //     }
    //     int down = dfs(grid,i-1, j, vis);
    //     if(down != INF) {
    //         res = min(res, 1+down);
    //     }
    //     vis[i][j]=false;
    //     return res;
    // }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if(grid.size()==0){
            return ;
        }
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            pair<int,int> top = q.front();
            q.pop();
            int r = top.first;
            int c = top.second;
            if(r+1<n&&grid[r+1][c]==INF){
                grid[r+1][c]=grid[r][c]+1;
                q.push({r+1,c});
            }
            if(c+1<m&&grid[r][c+1]==INF){
                grid[r][c+1]=grid[r][c]+1;
                q.push({r,c+1});
            }
            if(r-1>=0&&grid[r-1][c]==INF){
                grid[r-1][c]=grid[r][c]+1;
                q.push({r-1,c});
            }
            if(c-1>=0&&grid[r][c-1]==INF){
                grid[r][c-1]=grid[r][c]+1;
                q.push({r,c-1});
            }
        }
    }
};
