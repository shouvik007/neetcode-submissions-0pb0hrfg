class Solution {
public:
    void dfs(vector<vector<char>>& board , int i , int j,int n , int m) {
        if(i<0||j<0||i>=n||j>=m||board[i][j]!='O'){
            return;
        }
        board[i][j]='#';
        dfs(board, i-1, j, n,m);
        dfs(board, i+1, j, n,m);
        dfs(board, i, j+1, n,m);
        dfs(board, i, j-1, n,m);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m  = board[0].size();
        for(int i =0;i<n;i++){
            dfs(board, i , 0,n,m); //left;
            dfs(board, i, m-1,n,m); //right;
        }
        for(int i =0;i<m;i++){
            dfs(board, 0 , i,n,m); //up;
            dfs(board, n-1, i,n,m); //down;
        }
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if (board[i][j]=='#') {
                    board[i][j]='O';
                }
            }
        }
    }
};
