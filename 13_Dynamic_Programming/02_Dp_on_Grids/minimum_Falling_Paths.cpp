//Memoisation
class Solution {
private:
    int minSumPath(vector<vector<int>>& grid, int row, int col, int n, vector<vector<int>> &dp){
        if(row < 0 || col >= n || col < 0) return 1e9;
        //if row is zero return corresponding col element.
        if(row == 0){
            return grid[0][col];
        }
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        int leftDiagonal = grid[row][col] + minSumPath(grid, row-1, col-1, n, dp);
        int rightDiagonal = grid[row][col] + minSumPath(grid, row-1, col+1, n, dp);
        int up = grid[row][col] + minSumPath(grid, row-1, col, n, dp);
        return dp[row][col] = min(up, min(rightDiagonal, leftDiagonal));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        //check for each index in the last row(as greedy doesn't work)
        for(int j=0; j<n; j++){
            int ans = minSumPath(matrix, n-1, j, n, dp);
            mini = min(mini, ans);
        }
        return mini; 
    }
};

//Tabulation
class Solution {
// private:
//     int minSumPath(vector<vector<int>>& grid, int row, int col, int n, vector<vector<int>> &dp){
//         if(row < 0 || col >= n || col < 0) return 1e9;
//         if(row == 0){
//             return grid[0][col];
//         }
//         if(dp[row][col] != -1){
//             return dp[row][col];
//         }
//         int leftDiagonal = grid[row][col] + minSumPath(grid, row-1, col-1, n, dp);
//         int rightDiagonal = grid[row][col] + minSumPath(grid, row-1, col+1, n, dp);
//         int up = grid[row][col] + minSumPath(grid, row-1, col, n, dp);
//         return dp[row][col] = min(up, min(rightDiagonal, leftDiagonal));
//     }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int j=0; j<n; j++){
            dp[n-1][j] = grid[n-1][j];
        }
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<n; j++){
                int leftDiagonal = 1e9, rightDiagonal = 1e9, down = 1e9;
                if(j > 0){
                    leftDiagonal = grid[i][j] + dp[i+1][j-1];
                }
                if(j < n-1){
                    rightDiagonal = grid[i][j] + dp[i+1][j+1];
                }
                down = grid[i][j] + dp[i+1][j];
                dp[i][j] = min(down, min(leftDiagonal, rightDiagonal));
            }
        }
        int ans = INT_MAX;
        for(int j=0; j<n; j++){
            ans = min(ans, dp[0][j]);
        } 
        return ans;
    }
};

//Space optimisation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int mini = INT_MAX;
        vector<int> next(n, -1);
        for(int j=0; j<n; j++){
            next[j] = grid[n-1][j];
        }
        for(int i=n-2; i>=0; i--){
            vector<int> curr(n, 0);
            for(int j=0; j<n; j++){
                int leftDiagonal = 1e9, rightDiagonal = 1e9, down = 1e9;
                if(j > 0){
                    leftDiagonal = grid[i][j] + next[j-1];
                }
                if(j < n-1){
                    rightDiagonal = grid[i][j] + next[j+1];
                }
                down = grid[i][j] + next[j];
                curr[j] = min(down, min(leftDiagonal, rightDiagonal));
            }
            next = curr;
        }
        int ans = INT_MAX;
        for(int j=0; j<n; j++){
            ans = min(ans, next[j]);
        } 
        return ans;
    }
};
