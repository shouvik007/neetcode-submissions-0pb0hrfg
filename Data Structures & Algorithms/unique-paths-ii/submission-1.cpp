class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // Base case
        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If it is an obstacle, skip it (paths remain 0)
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                
                // Add paths from above (only if not at the top edge)
                if (i > 0) dp[i][j] += dp[i-1][j];
                
                // Add paths from left (only if not at the left edge)
                if (j > 0) dp[i][j] += dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};