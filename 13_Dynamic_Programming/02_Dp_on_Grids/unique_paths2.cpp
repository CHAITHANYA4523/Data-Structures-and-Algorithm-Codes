//Tabulation
class Solution {
private:
    int allPaths(vector<vector<int>>& obstacleGrid, int row, int col, vector<vector<int>>& dp){
        if(row == 0 && col == 0) return 1;
        if(row < 0 || col < 0) return 0;
        if(obstacleGrid[row][col] == 1){
            return 0;
        }
        if(dp[row][col] != -1) return dp[row][col];
        int up = allPaths(obstacleGrid, row-1, col, dp);
        int left = allPaths(obstacleGrid, row, col-1, dp);
        return dp[row][col] = left + up;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1) return 0;
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return allPaths(obstacleGrid, n-1, m-1, dp);
    }
};

//Space optimisation
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1) return 0;
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }
                else{
                    if(obstacleGrid[i][j] == 1){
                        dp[i][j] = 0;
                    }
                    else{
                        int up = 0;
                        if(j > 0){
                            up = dp[i][j-1];
                        }
                        int left = 0;
                        if(i > 0){
                            left = dp[i-1][j];
                        }
                        dp[i][j] = up + left;
                    }
                }
            }
        }
        return dp[n-1][m-1];
    }
};

/*
Time Complexity: O(N*M)
Reason: There are two nested loops

Space Complexity: O(N*M)
Reason: We are using an external array of size ‘N*M’’.
*/

/*
Time Complexity: O(N*M)
Reason: At max, there will be N*M calls of recursion.

Space Complexity: O((M-1)+(N-1)) + O(N*M)
Reason: We are using a recursion stack space:O((M-1)+(N-1)), here (M-1)+(N-1) is the path length and an external DP Array of size ‘N*M’.
*/