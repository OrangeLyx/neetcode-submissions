class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        if (grid[0][0] == 1 || grid[M - 1][N - 1] == 1) {
            return 0;
        }

        vector<vector<uint>> dp(M + 1, vector<uint>(N + 1, 0));
        dp[M - 1][N - 1] = 1;

        for (int r = M - 1; r >= 0; r--) {
            for (int c = N - 1; c >= 0; c--) {
                if (grid[r][c] == 1) {
                    dp[r][c] = 0;
                } else {
                    dp[r][c] += dp[r + 1][c];
                    dp[r][c] += dp[r][c + 1];
                }
            }
        }
        return dp[0][0];
    }
};