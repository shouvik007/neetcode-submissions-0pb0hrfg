class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int m = amount;
        vector<vector<int>>v(n, vector<int>(m+1,0));
        for(int i =0;i<n;i++){
            v[i][0]=1;
        }
        for(int i =1;i<=m;i++){
            if(i%coins[0]==0){
                v[0][i]= 1;
            }
            else {
                v[0][i]=0;
            }
        }
        for(int i =1;i<n;i++){
            for(int j=1;j<=m;j++){
                if(coins[i]>j){
                    v[i][j] = v[i-1][j];
                }
                else {
                    v[i][j]=v[i-1][j]+v[i][j-coins[i]];
                }
            }
        }
        return v[n-1][m];
    }
};
