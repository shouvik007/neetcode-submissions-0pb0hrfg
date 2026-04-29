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
                    bfs(grid,v,n,m, i ,j);
                    count++;
                }
            }
        }
        return count;
    }
    void bfs(vector<vector<char>>& grid,vector<vector<bool>>&v, int n, int m , int i , int j){
        queue<pair<int,int>>q;
        q.push({i,j});
        v[i][j]=true;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        while(!q.empty()){
            auto x = q.front();
            int a = x.first;
            int b = x.second;
            q.pop();
            for(int k=0;k<4;k++){
                int nx = a+dx[k];
                int ny = b+dy[k];
                if(nx<0||ny<0||nx>=n||ny>=m||grid[nx][ny]=='0'||v[nx][ny]==true){
                    continue;
                }
                else{
                    v[nx][ny]=true;
                    q.push({nx,ny});
                }
            }

        }
        
    }
};
