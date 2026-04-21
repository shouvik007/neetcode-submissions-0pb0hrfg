class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int m = amount+1;
        vector<vector<int>>a(n+1,vector<int>(m,INT_MAX-1));
        for(int i =0;i<=n;i++){
            a[i][0] = 0;
        }
        for(int i =0;i<m;i++){
            a[0][i] = INT_MAX - 1;
        }
        for(int i =1;i<=n;i++){
            for(int j =1;j<m;j++){
                if(coins[i-1]>j){
                    a[i][j]=a[i-1][j];
                }
                else {
                    a[i][j]=min(a[i-1][j],(1+a[i][j-coins[i-1]]));
                }
            }
        }
        if(a[n][m-1]!=INT_MAX-1){
            return a[n][m-1];
        }
        return -1;
    }
};
